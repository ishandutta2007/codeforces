#include<bits/stdc++.h>
using namespace std;
int T,n,m,pre[1000005];
char s[1000005];
int cnt[1000005];
int ans[1000005];
void sol(){
	scanf("%d%d%s",&n,&m,s+1);
	for(int i=1;i<=n*m;i++)
		pre[i]=pre[i-1]+(s[i]=='1');
	for(int i=0;i<=n*m;i++)cnt[i]=ans[i]=0;
	int cur=0;
	for(int i=1;i<=n*m;i++){
		if(s[i]=='1'){
			cnt[i%m]++;
			if(cnt[i%m]==1)cur++;
		}
		ans[i%m]+=(pre[i]-pre[max(i-m,0)]>0);
		printf("%d ",cur+ans[i%m]);
	}
		puts("");
}
int main(){
	scanf("%d",&T);
	while(T--)sol();
}