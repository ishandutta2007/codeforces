#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 1e6 + 10;

int n, k, a[MAXN], cnt[MAXN];
set<pii> st;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k, k--;
	for (int i = 0; i < MAXN; i++) st.insert({0, i});
	for (int i = 0; i < n; i++){
		cin >> a[i], a[i]--;
		if (st.count({cnt[a[i]], a[i]})){
			st.erase({cnt[a[i]], a[i]});
			cnt[a[i]]++;
			st.insert({cnt[a[i]], a[i]});
		}
		while (st.begin()->F < cnt[k])
			st.erase(st.begin());
	}
	if (st.begin()->S == k) st.erase(st.begin());
	if (st.size())
		cout << st.begin()->S+1 << "\n";
	else
		cout << "-1\n";
	return 0;
}