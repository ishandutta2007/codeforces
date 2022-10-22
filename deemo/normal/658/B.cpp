#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#include<set>

using namespace std;

const int MAXN = 2e5 + 10;

int n, k, q, val[MAXN];
set<pair<int, int>>	st;
bool on[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k >> q;
	for (int i = 0; i < n; i++)	cin >> val[i];
	while (q--){
		int type;	cin >> type;
		if (type == 1){
			int id;	cin >> id;	id--;
			on[id] = 1;
			st.insert({val[id], id});
			if (st.size() > k){
				on[st.begin()->second] = 0;
				st.erase(st.begin());
			}
		}
		else{
			int id;	cin >> id;	id--;
			cout << (on[id]?"YES\n":"NO\n");
		}
	}
	return	0;
}