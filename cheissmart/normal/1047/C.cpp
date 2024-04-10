#include <bits/stdc++.h>

using namespace std;

const int N = 312345, C = 15234567;

int a[N], sp[C];

void pre()
{
	vector<int> p;
	for (int i = 2; i < C; i++) {
		if (!sp[i]) {
			sp[i] = i;
			p.push_back(i);
		}
		for (int j : p) {
			if (i * 1LL * j >= C)
				break;
			sp[i * j] = j;
			if (j == sp[i])
				break;
		}
	}
}
int gcd(int m, int n) { 
    if(n == 0) 
        return m; 
    else 
        return gcd(n, m % n); 
}

int main()
{
	int n;
	map<int, int> mp;
	cin >> n;
	int g = 0;
	for(int i=0;i<n;i++) {
		cin >> a[i];
		g = gcd(a[i], g);
	}
	pre();
	for(int i=0;i<n;i++)
		a[i] /= g;
	for(int i=0;i<n;i++) {
		set<int> st;
		while(a[i] > 1) {
			st.insert(sp[a[i]]);
			a[i] /= sp[a[i]];
		}
		for(int d:st) {
			mp[d]++;
		}
	}
	int ans = 0;
	for (auto it = mp.begin(); it != mp.end(); it++)
		ans = max(ans, it->second);
	if (!ans)
		cout << -1 << endl;
	else
		cout << n - ans << endl;
	
}