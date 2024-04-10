#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<set>
#include<utility>

using namespace std;

#define F first
#define S second

const int MAXN = 1e5 + 10;
const int XX = 1e6 + 10;

int sz = 0;
pair<int, int>	vec[XX];
multiset<int>	st;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int q;	cin >> q;
	while (q--){
		string temp;	cin >> temp;
		if (temp[0] == 'i'){
			int x;	cin >> x;
			st.insert(x);
			vec[sz++] = {0, x};
		}
		else if (temp[0] == 'g'){
			int x;	cin >> x;
			while (st.size() && *st.begin() < x){
				vec[sz++] = {2, 0};
				st.erase(st.begin());
			}
			if (st.empty() || *st.begin() != x){
				vec[sz++] = {0, x};
				st.insert(x);
			}
			vec[sz++] = {1, x};
		}
		else{
			if (st.empty()){
				st.insert(1);
				vec[sz++] = {0, 1};
			}
			st.erase(st.begin());
			vec[sz++] = {2, 0};
		}
	}

	cout << sz << "\n";
	for (int i = 0; i < sz; i++){
		auto ans = vec[i];
		if (ans.F == 0)
			cout << "insert " << ans.S << "\n";
		if (ans.F == 1)
			cout << "getMin " << ans.S << "\n";
		if (ans.F == 2)
			cout << "removeMin" << "\n";
	}
	return 0;
}