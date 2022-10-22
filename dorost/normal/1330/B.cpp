#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main(){
	int t = 1;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		int a[n];
		set <int> s;
		bool mp[n + 1] = {}, m[n + 1] = {};
		for (int i = 0; i < n; i++){
			cin >> a[i];
		}
		for (int i = 0; i < n; i++){
			if (s.count(a[i])){
				break;
			}
			s.insert(a[i]);
			if (*s.rbegin() == i + 1){
				mp[i + 1] = true;
				//cut << "% mp " << i + 1 << endl;
			}
		}
		s.clear();
        for (int i = n - 1; i >= 0; i--){
            if (s.count(a[i])){
                break;
            }
			s.insert(a[i]);
            if (*s.rbegin() == n - i){
                m[n - i] = true;
				//cout << "% m " << i + 1 << endl;
            }
        }
		int k = 0;
		for (int i = 1; i <= n; i++){
			if ((mp[i] && m[n - i])){
				k ++;
			}
		}
		cout << k << endl;
        for (int i = 1; i <= n; i++){
            if ((mp[i] && m[n - i])){
                cout << i << ' ' << n - i << endl;
            }
        }
	}
}