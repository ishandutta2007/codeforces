#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;

const int MAXN = 4 * 100 * 1000;
	int a[MAXN], maxi = 0, x = 0, ans[MAXN];
int main(){
	int n;
	cin >> n;
	deque <int> v;

	for (int i = 0; i < MAXN; i++){
		a[i] = ans[i] = 0;
	}
	v.clear();
	map <int, bool> mp;
	mp.clear();
	for (int i = 0; i < n; i++){
		cin >> a[i];
		if(a[i] != 0){
			mp[a[i] - 1] = true;
		}
	}
	for (int i = 0; i < n; i++){
		if (mp[i] == false) {
			v.push_back(i + 1);
		}
	}
	reverse(v.begin(), v.end());
	for (auto x : v){
		cerr << x << " ";
	}
	cerr << endl;
	int m = 0;
	for (int i = 0; i < n; i++){
		if (a[i] != 0){
			cout << a[i] << ' ';
		}else{
			int x = 0;
			for (int j = i + 1; j < n; j++){
				if(a[j] == 0){
					x = j;
					break;
				}
			}
			if(v[m + 1] == x + 1){
				swap(v[m], v[m + 1]);
			}
			if(v[m] == i + 1){
				swap(v[m], v[m + 1]);
			}
			cout << v[m] << ' ';
			m ++;
		}
	}
}