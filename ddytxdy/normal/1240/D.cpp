#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=3e5+50;
map<int,int>nxtX[N];
int t,n,a[N],nxt[N],f[N];LL ans;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);ans=0;
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=n;i;i--){
			if(nxtX[i+1].count(a[i])){
				int p=nxtX[i+1][a[i]];nxt[i]=p;
				swap(nxtX[i],nxtX[p+1]);
			}
			nxtX[i][a[i]]=i;
		}
		for(int i=n;i;i--){
			if(nxt[i])f[i]=f[nxt[i]+1]+1;
			ans+=f[i];
		}
		cout<<ans<<endl;
		for(int i=1;i<=n;i++)nxt[i]=f[i]=0,nxtX[i].clear();
	}
	return 0;
}