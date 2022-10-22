#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int main(){
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int t;
	cin >> t;
	while (t--){
		int n, m;
		cin >> n >> m;
		int b[m], x;
		pair <int, int> a[n];
		map <pair <int, int>, bool> We_can_go_from_first_to_second;
		for (int i = 1; i <= n; i++){
			We_can_go_from_first_to_second[make_pair(i, i)] = true; 
		}
		for (int i = 0; i < n; i++){
			cin >> x;
			a[i] = make_pair(x, i);
		}
		for (int i = 0; i < m; i++){
			cin >> b[i];
		}
		sort (b, b + m);
		for (int i = 0; i < m; i++){
			for (int j = 1; j < b[i]; j++){
				if (We_can_go_from_first_to_second[make_pair(j, b[i])] == true){ // if we can go from j to b[i] then we can go from j to b[i] + 1 because we can go from b[i] to b[i] + 1 
					We_can_go_from_first_to_second[make_pair(j, b[i] + 1)] = true;
				}
			}
			We_can_go_from_first_to_second[make_pair(b[i], b[i] + 1)] = true; // And we can go from b[i] to b[i] + 1
		}
		bool f = true;
		sort (a, a + n);
		for (int  i = 0; i < n; i++){
			if (We_can_go_from_first_to_second[make_pair(i + 1, a[i].S + 1)] == false && We_can_go_from_first_to_second[make_pair(a[i].S + 1, i + 1)] == false){ // if we cant go from first posation to second posation and revere
				f = false;
				break;
			}
		}
		cout << (f ? "YES" : "NO") << endl;
	}
}