#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
#define next Cry_For_theMoon
typedef long long ll;
using namespace std;
const int MAXN=2e5+10,LIM=2e5;
int T,n,a[MAXN],f[MAXN],t[MAXN];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		memset(f,0,sizeof f);
		memset(t,0,sizeof t);
		rep(i,1,n){
			scanf("%d",&a[i]);
			t[a[i]]++;
			f[a[i]]=t[a[i]]; 
		}
		int ans=0;
		rep(i,1,LIM){
			for(ll j=i+i;j<=LIM;j+=i){
				if(!t[j])continue;
				f[j]=max(f[j],f[i]+t[j]);
			}
			ans=max(ans,f[i]);
		}
		printf("%d\n",n-ans);
	}
	
	return 0;
}