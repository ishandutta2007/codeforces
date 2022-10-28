#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'
#define T long double
const int N=305;
int n;
int x[N];
int y[N];
int dp[N][N][6]; 

T f(int i, int j){
	return atan2(y[j]-y[i], x[j]-x[i]);
}

main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>x[i]>>y[i];
	}
	vector<pair<T, pair<int, int>>>vec;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(i==j){
				continue;
			}
			T val=f(i, j);
			vec.pb({val, {i, j}});
		}
	}
	sort(vec.begin(), vec.end());
	for(int i=0; i<n; i++){
		dp[i][i][0]=1;
	}
	for(auto uu:vec){
		int u=uu.s.f;
		int v=uu.s.s;
		for(int i=1; i<=5; i++){
			for(int j=0; j<n; j++){
				dp[j][v][i]+=dp[j][u][i-1];
			}
		}
	}
	int ans=0;
	for(int i=0; i<n; i++){
		ans+=dp[i][i][5];
	}
	cout<<ans;
	return 0;
}