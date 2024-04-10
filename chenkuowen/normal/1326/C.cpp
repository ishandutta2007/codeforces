#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX_N=5+2e5,MOD=998244353;
int p[MAX_N];
vector<int> pos;
int main(){
	ll ans1=0;
	int ans2=1;
	int n,k; scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i){
		scanf("%d",&p[i]);
		if(p[i]>=n-k+1) pos.push_back(i),ans1+=p[i];
	}
	for(int i=1;i<pos.size();++i)
		ans2=1ll*ans2*(pos[i]-pos[i-1])%MOD;
	printf("%lld %d\n",ans1,ans2);
	return 0;
}