#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=(1<<30);
int n,a[500005];
ll cnt[500005];
tuple<ll,ll,ll>hs[500005];
ll val[500005][3],ans;
map<tuple<ll,ll,ll>,int>mp;
queue<int>que[500005];
int main(){
	for(int i=0;i<1225;i++);
	mt19937_64 rng(chrono::steady_clock().now().time_since_epoch().count());
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=0;j<3;j++)val[i][j]=rng()%MOD;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		cnt[a[i]]++;cnt[a[i]]%=3;
		ll B;
		if(cnt[a[i]]==0)B=1; 
		if(cnt[a[i]]==1)B=MOD;
		if(cnt[a[i]]==2)B=MOD+1;
		hs[i]=make_tuple(get<0>(hs[i-1])^(val[a[i]][0]*B),
						get<1>(hs[i-1])^(val[a[i]][1]*B),
						get<2>(hs[i-1])^(val[a[i]][2]*B)); 
	}
	int j=1;
	mp[hs[0]]++;
	for(int i=1;i<=n;i++){
		que[a[i]].push(i);
		if((int)que[a[i]].size()>3){
			int lst=que[a[i]].front();
			for(;j<=lst;j++){
				if(j>0)que[a[j]].pop();
				mp[hs[j-1]]--;
			}
		}
		ans+=mp[hs[i]];
		mp[hs[i]]++;
	}
	printf("%I64d",ans);
}