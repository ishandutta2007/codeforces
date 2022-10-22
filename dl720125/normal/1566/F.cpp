#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define int long long
#define INF 1000000000000000007ll
using namespace __gnu_pbds;
using namespace std;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int n,m,a[200010],val[200010][2][2];
int dp[200010][2];
pair<int,int> b[200010];
vector<pair<int,int> > v[200010];

signed main()
{
	ios::sync_with_stdio(false);
	int t;cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+n+1);
		for(int i=1;i<=n+1;i++) v[i].clear();
		for(int i=1;i<=m;i++){
			cin>>b[i].first>>b[i].second;
			int pos=lower_bound(a+1,a+n+1,b[i].first)-a;
			if(!(pos>=1&&pos<=n&&a[pos]<=b[i].second)){
				v[pos].push_back(make_pair(b[i].first,b[i].second));
			}
		}
		int ans=0;
		a[0]=-INF;a[n+1]=INF; 
		for(int i=1;i<=n+1;i++){
			multiset<pair<int,int> > s;
			if(!v[i].empty()){
				sort(v[i].begin(),v[i].end());
				for(int j=0;j<v[i].size();j++){
					s.insert(v[i][j]);
					while(s.size()>1){
						multiset<pair<int,int> >::iterator it=s.end();
						it--;pair<int,int> x1=*it;
						it--;pair<int,int> x2=*it;
						if(x2.first<=x1.first&&x2.second>=x1.second){
							s.erase(it);
						}
						else break;
					}
				}
			}
			vector<pair<int,int> > res;
			res.push_back(make_pair(a[i-1],INF));
			if(!v[i].empty()){	
				for(multiset<pair<int,int> >::iterator it=s.begin();it!=s.end();it++){
					res.push_back(*it);
				}
			}
			res.push_back(make_pair(INF,a[i]));
			val[i][0][0]=val[i][0][1]=val[i][1][0]=val[i][1][1]=INF;
			for(int j=1;j<res.size();j++){
				val[i][0][0]=min(val[i][0][0],abs(a[i-1]-res[j-1].first)+abs(a[i]-res[j].second));
				val[i][0][1]=min(val[i][0][1],abs(a[i-1]-res[j-1].first)+abs(a[i]-res[j].second)*2);
				val[i][1][0]=min(val[i][1][0],abs(a[i-1]-res[j-1].first)*2+abs(a[i]-res[j].second));
				val[i][1][1]=min(val[i][1][1],abs(a[i-1]-res[j-1].first)*2+abs(a[i]-res[j].second)*2);
			}
		}
		dp[1][0]=min(val[1][0][0],val[1][1][0]);dp[1][1]=min(val[1][0][1],val[1][1][1]);
		for(int i=2;i<=n+1;i++){
			dp[i][0]=INF;dp[i][1]=INF;
			dp[i][0]=min(dp[i][0],dp[i-1][0]+val[i][1][0]);
			dp[i][0]=min(dp[i][0],dp[i-1][1]+val[i][0][0]);
			dp[i][1]=min(dp[i][1],dp[i-1][0]+val[i][1][1]);
			dp[i][1]=min(dp[i][1],dp[i-1][1]+val[i][0][1]);
		}
		cout<<min(dp[n+1][0],dp[n+1][1])<<'\n';
	}
	return 0;
}