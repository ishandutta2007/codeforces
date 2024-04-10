#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;

int n;
set<int> st;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	int cur = n;
	for (int i = 0; i < n; i++){
		int x;	cin >> x;
		st.insert(x);
		while (st.size() && *st.rbegin() == cur){
			cout << cur-- << " ";
			st.erase(cur+1);
		}
		cout << "\n";
	}
	return 0;
}