#include<bits/stdc++.h>

using namespace std;

#define FAIL {cout << "-1\n"; return 0;}

const int MAXN = 2e5 + 10;

int n, m, a[MAXN], ans;
int x, y;
set<int>	st;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		if (st.count(a[i]))
			a[i] = -1;
		else{
			st.insert(a[i]);
			if (a[i] & 1)
				y++;
			else
				x++;
		}
	}

	int odd = 1, even = 2;
	for (int i = 0; i < n; i++)
		if (a[i] == -1){
			if (x > y){
				while (st.count(odd))	odd += 2;
				if (odd > m)	FAIL
				a[i] = odd;
				st.insert(odd);
				y++;
				ans++;
			}
			else{
				while (st.count(even))	even += 2;
				if (even > m)	FAIL
				a[i] = even;
				st.insert(even);
				x++;
				ans++;
			}
		}
	
	for (int i = 0; i < n; i++)
		if (x > y && a[i]%2==0){
			while (st.count(odd))	odd += 2;
			if (odd > m)	FAIL
				a[i] = odd;
			st.insert(odd);
			y++;
			x--;
				ans++;
		}
		else if (x < y && a[i]&1){
			while (st.count(even))	even += 2;
			if (even > m)	FAIL
				a[i] = even;
			st.insert(even);
			x++;
			y--;
				ans++;
		}

	cout << ans << "\n";
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << "\n";
	return 0;
}