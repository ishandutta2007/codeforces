#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

const int N = 100;

struct state {
	int a, u, i;
	state(int a, int u, int i):a(a),u(u),i(i){}
};

vector<state> v;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n,w;
	cin >> n >> w;
	for(int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		int u = (a+1)/2;
		v.pb(state(a,u,i));
		w -= u;
	}
	if(w<0) {
		cout << "-1\n";
		return 0;
	}
	sort(v.begin(),v.end(),[=](const state &a, const state &b){return a.a < b.a;});
	while(w) {
		for(int i = n-1; w && i >= 0; --i) {
			if(v[i].a-v[i].u == 0) break;
			--w;
			++v[i].u;
		}
	}
	sort(v.begin(),v.end(),[=](const state &a, const state &b){return a.i < b.i;});
	for(auto &s : v)
		cout << s.u << " ";
	cout << "\n";
}