#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector <int> S;
	int t, n, i, a;

	cin >> t;

	for(; t --; ){
		cin >> n; cin >> a;
		S.clear(); S.push_back(a);
		for(i = 1; i < n; i ++){
			cin >> a;
			for(; S.size() > 1; S.pop_back()){
				if(S.back() > a){
					S.push_back(a);
					break;
				}
			}
			if(S.size() == 1 && S.back() > a){
				S.push_back(a);
			}
		}
		cout << (S.size() == 1? "YES" : "NO") << "\n";
	}

	return 0;
}