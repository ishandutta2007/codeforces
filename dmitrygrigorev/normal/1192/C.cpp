#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 998244353;
const int K = 26;
int sum(int x, int y){
	if (x+y<0) return x+y+mod;
	if (x+y >= mod) return x+y-mod;
	return x+y;
}
int mult(int x, int y){
	return ((ll) x * (ll) y) % (ll) mod;
}
int ans = 0;
int get(char symb){
	if (symb >= 'a' && symb <= 'z') return symb-'a';
	if (symb >= 'A' && symb <= 'Z') return K+(symb-'A');
	return 2*K + (symb-'0');
}
int ways[2*K+10][2*K+10][2*K+10];
int dp[2*K+10][2*K+10];
void solve(vector<string> v){
	int s = v.size();
	for (int i=0; i < s; i++){
		string t = v[i];
		reverse(t.begin(), t.end());
		v.push_back(t);
	}
	sort(v.begin(), v.end());
	vector<string> nv;
	if (!v.size()) return;
	nv = {v[0]};
	for (int i=1; i < v.size(); i++) if (v[i] != v[i-1]) nv.push_back(v[i]);
	v = nv;
	for (int i=0;i<2*K+10;i++) for (int j=0;j<2*K+10;j++) dp[i][j] = 0;
	for (int i=0; i < v.size(); i++){
		int A = get(v[i][0]), B = get(v[i].back());
		dp[A][B]++;
	}
	for (int i=0; i < 2*K+10; i++) for (int j=i; j < 2*K+10; j++) for (int k=j; k < 2*K+10; k++){
		int tot = 0;
		for (int e=0; e < (2*K+10); e++){
			tot = sum(tot, mult(dp[i][e], mult(dp[j][e], dp[k][e])));
		}
		ways[i][j][k] = tot;
	}
	for (int i=0; i < (2*K+10); i++) for (int j=i; j < (2*K+10); j++) for (int k=j; k < (2*K+10); k++) for (int e=k; e < (2*K+10); e++){
		int T = 1;
		T = mult(T, ways[i][j][k]);
		T = mult(T, ways[i][j][e]);
		T = mult(T, ways[i][k][e]);
		T = mult(T, ways[j][k][e]);
		if (j!=i && k!=j && e != k){
		    ans = sum(ans, mult(T, 24));
		}
		if (i==j && j== k && k==e){
		    ans = sum(ans, T);
		}
		if (i==j && j==k && k != e){
		    ans = sum(ans, mult(T, 4));
		}
		if (i==j && j!= k && k==e){
		    ans = sum(ans, mult(T, 6));
		}
		if (i==j && j!= k && k!=e){
		    ans = sum(ans, mult(T, 12));
		}
		if (i!=j && j!= k && k==e){
		    ans = sum(ans, mult(T, 12));
		}
		if (i!=j && j== k && k!=e){
		    ans = sum(ans, mult(T, 12));
		}
		if (i!=j && j== k && k==e){
		    ans = sum(ans, mult(T, 4));
		}
	}
}
signed main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<vector<string> > tet(8);
    for (int i=0;i<n;i++){
    	string s;
    	cin >> s;
    	tet[s.size()-3].push_back(s);
    }
    for (int i=0;i<8;i++) solve(tet[i]);
    	cout << ans;
}