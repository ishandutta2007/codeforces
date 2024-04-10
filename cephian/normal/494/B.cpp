#include <bits/stdc++.h>
#define print(x) cerr << #x << " = " << x << endl;
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

struct kmp {
	int N;
	const string S;
	vector<int> F;

	kmp(){}
	kmp(const string S): N(S.size()), S(S), F(N+1) {
		for(int i = 1; i < N; ++i)
			F[i+1] = advance(F[i], S[i]);
	}

	int advance(int j, char x) {
		while(j && (j >= N || S[j] != x)) j = F[j];
		if(S[j] == x) ++j;
		return j;
	}

	vector<int> matches(const string T) {
		vector<int> ans;
		int j = 0;
		for(int i = 0; i < (int)T.size(); ++i) {
			j = advance(j, T[i]);
			if(j == N)
				// MATCH FOUND AT FROM i-|S|+1 ... i, ZERO-INDEXED
				ans.push_back(i); 
		}
		return ans;
	}
};

const ll M = 1e9+7;

int main() {
	ios::sync_with_stdio(0);
	string s, t;
	cin >> s >> t;
	kmp k(t);
	auto matches = k.matches(s);
	vector<ll> dp(s.size()+1);
	vector<ll> dps(s.size()+1);
	dp[0] = dps[0] = 1;
	int cur = 0;
	int last = 0;
	for(int i = 1; i <= (int)s.size(); ++i) {
		if(cur != (int)matches.size() && matches[cur]+1 == i) {
			dp[i] = (dp[i-1] + dps[i-t.size()]) % M;
			last = i;
			++cur;
		} else {
			if(last == 0)
				dp[i] = 1;
			else 
				dp[i] = ((dp[last] - dp[last-1]) * (i-last+1) + dp[last-1]) % M;
		}
		if(dp[i] < 0) dp[i] += M;
		dps[i] = (dp[i] + dps[i-1]) % M;
	}
	cout << (dp[s.size()]+M-1) % M << "\n";
}