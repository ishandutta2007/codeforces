/* 	* In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main(){
	int t;
	cin >> t;
	while (t--){
		int n, m, x;
		cin >> n >> x >> m;
		int fst = -1, lst = -1;
		for (int i = 0; i < m; i++){
			int l, r;
			cin >> l >> r;
			if (fst == -1){
				if (x >= l && x <= r){
					fst = l;
					lst = r;
				}
			}else{
				if ((fst >= l && fst <= r) || (lst >= l && lst <= r)){
					fst = min(fst, l);
					lst = max(lst, r);
				}
			}
		}
		cout << lst - fst + 1 << endl;
	}
}