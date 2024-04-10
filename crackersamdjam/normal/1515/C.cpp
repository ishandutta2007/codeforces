#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T,typename... Args> void pr(T a, Args... args) {std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;
using pii = pair<int, int>;
const int MM = 1e5+5;

int t, n, m, x;
pair<int, int> a[MM];
int sum[MM], id[MM];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	
	cin>>t;
	while(t--){
		cin>>n>>m>>x;
		for(int i = 0; i < n; i++){
			cin>>a[i].first;
			a[i].second = i;
		}
		sort(a, a+n);

		priority_queue<pii, vector<pii>, greater<pii>> q;
		
		for(int i = 1; i <= m; i++){
			sum[i] = 0;
			q.emplace(0, i);
		}

		for(int i = n-1; i >= 0; i--){
			int u = q.top().second; q.pop();
			sum[u] += a[i].first;
			id[a[i].second] = u;
			q.emplace(sum[u], u);
		}

		int mx = *max_element(sum+1, sum+m+1);
		int mn = *min_element(sum+1, sum+m+1);
		int dif = mx-mn;
		if(dif > x){
			cout<<"NO\n";
			continue;
		}

		cout<<"YES\n";
		for(int i = 0; i < n; i++)
			cout<<id[i]<<' ';
		cout<<'\n';
	}
}