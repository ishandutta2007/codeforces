#include <bits/stdc++.h>
using namespace std;
int dp[5001];
int INF = 1e8;
vector<int> pi;
vector<int> prefix_function (string s) {
	int n = (int) s.length();
	pi.assign(n, 0);
	for (int i=1; i<n; ++i) {
		int j = pi[i-1];
		while (j > 0 && s[i] != s[j])
			j = pi[j-1];
		if (s[i] == s[j])  ++j;
		pi[i] = j;
	}
	return pi;
}
bool substring(string &s, string &t){
    string g = t + '#' + s;
    vector<int> kek = prefix_function(g);
    for (int i=0; i < kek.size(); i++) if (kek[i] == t.size()) return true;
    return false;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    int n,a,b;
    cin >> n >> a >> b >> s;
    for (int i=0; i <= n; i++) dp[i] = INF;
    dp[0] = 0, dp[1] = a;
    string S,T;
    int border = 1;
    for (int i=2; i <= n; i++){
        dp[i] = min(dp[i], dp[i-1] + a);
        int L = 0, R = i;
        while (border < i){
            S="", T="";
            for (int j=0; j < border; j++) S += s[j];
            for (int j=border; j < i; j++) T += s[j];
            if (substring(S, T)) break;
            else border++;
        }
        for (int j=0; j < i; j++){
            if (j >= border) dp[i] = min(dp[i], dp[j]+b);
        }
    }
    cout << dp[n];



}