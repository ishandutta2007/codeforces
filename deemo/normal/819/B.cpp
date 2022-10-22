#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 2e6 + 10;

int n, p[MAXN], mark[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> p[i], p[i]--;
	ll cur = 0;
	int cGood = 0, cBad = 0;
	for (int i = 0; i < n; i++){
		cur += abs(p[i]-i);
		if (p[i] >= i) cGood++;
		else{
			cBad++;
			mark[i-p[i]-1]++;
		}
	}
	
	pair<ll, int> ans(cur, 0);
	for (int i = 0; i+1 < n; i++){
		cur += cGood;
		cur -= cBad;
		cGood += mark[i];
		cBad -= mark[i];
		
		cur -= p[i]+1;

		cGood--;
		if (p[i] >= n-1)
			cGood++;
		else{
			cBad++;
			mark[n-1-p[i]+i]++;
		}
		cur += n-1-p[i];

		ans = min(ans, {cur, n-i-1});
	}
	cout << ans.F << " " << ans.S << endl;
	return 0;
}