#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

int ans[100005], t[100005];
queue<int> q;
set<int> inq, want;
set<pi> st;

int32_t main()
{
	IO_OP;
	
	int n, p, tm = 0;
	cin >> n >> p;
	for(int i=0;i<n;i++) {
		cin >> t[i];
		st.insert({t[i], i});
	}
	while(st.size()) {
		int i = st.begin()->S;
		st.erase(st.begin());
		q.push(i);
		inq.insert(i);
		tm = t[i];
		while(q.size()) {
			int j = q.front();
			ans[j] = tm += p;
			while(st.size() && t[st.begin()->S] < tm) {
				if(inq.empty() || (*inq.begin()) > st.begin()->S) {
					q.push(st.begin()->S);
					inq.insert(st.begin()->S);
				} else {
					want.insert(st.begin()->S);
				}
				st.erase(st.begin());
			}
			q.pop();
			inq.erase(j);
			if(st.size() && t[st.begin()->S] == tm) {
				want.insert(st.begin()->S);
				st.erase(st.begin());
			}
			while(want.size() && (inq.empty() || (*want.begin()) < (*inq.begin()))) {
				q.push(*want.begin());
				inq.insert(*want.begin());
				want.erase(want.begin());
			}
		}
	}

	for(int i=0;i<n;i++) cout << ans[i] << " \n"[i==n-1];

}