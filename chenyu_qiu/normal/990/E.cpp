#include<bits/stdc++.h>
using namespace std;
int s[1000000+10],sl[1000000+10];
bool vis[2000000+10];
int a[1000000+10];
struct price
{
    int a;//
    int l;//
}P[1000000+10];
int main() {
    int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
    int max_block=0,l=1;
	memset(vis,0,sizeof(vis));
	memset(s,-1,sizeof(s));
    for(int i=0;i<m;i++){
		scanf("%d",&s[i]);
		vis[s[i]] = 1;
		if(i==0) {
			sl[s[i]] = s[i] -1; 
			continue;
		}
        if(s[i]==s[i-1]+1) {
			l += 1; 
			sl[s[i]] = sl[s[i-1]];
		}
        else{
            max_block = max(l+1,max_block);
			sl[s[i]] = s[i]-1;
			l = 1;
        }
    } 
	int x = 0;
	if(l>1&&s[m-1]==n) max_block = max(l,max_block);
	else if(l>1) max_block = max(l+1,max_block);
	else if(m==1&&s[m-1]==n) max_block =max(l,max_block);
	else if(m==1) max_block =max(l+1,max_block);
    for(int i=0;i<k;i++) {
		scanf("%d",&a[i]);
        if(i+1>=max_block) {
            P[x].a = a[i],P[x].l = i+1,x++;//
        }
    }
    if(max_block>k||s[0]==0) printf("-1\n");
    else{
        long long ans = 1e13;
		for(int i=0;i<x;i++){
			long long tmp = 0;
			int r =0; 
			while(r<n){
				tmp += P[i].a;
				r = r+P[i].l;
				if(vis[r]==1) r = sl[r];
			}	
			ans = min(ans,tmp);
		}
		printf("%lld\n",ans);
    }
	return 0;
 
}