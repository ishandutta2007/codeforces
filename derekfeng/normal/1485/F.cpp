#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
int n,T,ans,x;
ll k;
unordered_map<ll,int>mp;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);mp.clear();
		ans=1,k=0;mp[0]=1;
		for(int i=0;i<n;i++){
			scanf("%d",&x);
			int a=mp[k];mp[k]=ans;k-=x;
			(((ans+=ans)%=mod)+=mod-a)%=mod;
		}
		printf("%d\n",ans);
	}
}