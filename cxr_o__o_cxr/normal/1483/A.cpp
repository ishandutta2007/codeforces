//starusc
#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1,c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f==1?x:-x;
}
const int N=1e5+4;
int n,m,c1[N],c2[N],ans[N];
vector<int>vec[N];
inline void solve(){
	memset(c1,0,sizeof(int)*(n+1));
	memset(c2,0,sizeof(int)*(n+1));
	for(int i=1;i<=m;i++)vec[i].clear();
	
	n=read();m=read();
	for(int i=1,k,x;i<=m;i++){
		k=read();
		for(int j=1;j<=k;j++){
			vec[i].push_back(x=read());
			c2[x]++;
		}
		if(k==1)c1[x]++;
	}
	for(int i=1;i<=n;i++)if(c1[i]>((m+1)>>1)){
		puts("NO");
		return;
	}
	puts("YES");
	for(int i=1,res,fl;i<=n;i++)if(c2[i]>=((m+1)>>1)){
		res=((m+1)>>1)-c1[i];
		for(int j=1;j<=m;j++){
			if(vec[j].size()==1&&vec[j][0]==i){
				ans[j]=i;
				continue;
			}
			fl=0;
			for(auto v:vec[j])if(res&&v==i){
				ans[j]=v;
				res--;
				fl=1;
				break;
			}
			if(!fl)for(auto v:vec[j])if(v!=i){
				ans[j]=v;
				break;
			}
		}
		for(int j=1;j<=m;j++)cout<<ans[j]<<" ";puts("");
		return;
	}
	for(int i=1;i<=m;i++)cout<<vec[i][0]<<" ";puts("");
}
int main(){
	for(int T=read();T--;)solve();
	return (0-0);
}