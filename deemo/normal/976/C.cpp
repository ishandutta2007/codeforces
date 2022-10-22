#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 3e5 + 10;

int n;
pii seg[MAXN];
set<pii> st;
int sec[MAXN];

bool cmp(int u, int v){
	if (seg[u].S^seg[v].S)
		return seg[u].S < seg[v].S;
	return seg[u].F > seg[v].F;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> seg[i].F >> seg[i].S;
	iota(sec, sec + n, 0);
	sort(sec, sec + n, cmp);

	for (int i = 0; i < n; i++){
		int id = sec[i];
		auto it = st.lower_bound({seg[id].F, -1});
	
		if (it != st.end()){
			cout << it->S+1 << " " << id+1 << endl;
			return 0;
		}
		st.insert({seg[id].F, id});
	}

	cout << "-1 -1\n";
	return 0;
}