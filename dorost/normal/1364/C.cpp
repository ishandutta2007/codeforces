/* 	* In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 101234;
int a[N], ans[N];

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	bool f = true;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		ans[i] = -1;
	}
	int mx = -1;
	for (int i = 0; i < n; i++){
		int x = a[i] - 1;
		int ind = i;
		for (int j = mx + 1; j <= x;){
			if (ans[ind] == -1){
				ans[ind] = j;
				j++;
				ind --;
			}else{
				ind --;
			}
		}
		mx = max(mx, x);
	}
	set <int> st;
	for (int i = 0; i <= N; i++){
		st.insert (i);
	}
	for (int i = 0; i < n; i++){
		st.erase(ans[i]);
		int x = *st.begin();
		if (x != a[i])
			f = false;
	}
	if (!f){
		cout << -1;
		return 0;
	}
	for (int i = 0; i < n; i++){
		if (ans[i] == -1){
			ans[i] = N;
		}
		cout << ans[i] << ' ';
	}
}