#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;

int n;
set<int>	st;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++){
		int temp;	cin >> temp;
		st.insert(temp);
	}

	while (1){
		auto it = st.end();	it--;
		if (*it == 1)	break;
	
		int v = *it;
		st.erase(it);
		int temp = v;
		while (v){
			v >>= 1;
			if (v == 0)	break;
			if (st.count(v) == 0){
				st.insert(v);
				break;
			}
		}

		if (st.size() < n){
			st.insert(temp);
			break;
		}
	}

	for (int x:st)
		cout << x << " ";
	cout << "\n";
	return 0;
}