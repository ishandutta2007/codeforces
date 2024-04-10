/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main(){
	int n;
	cin >> n;
	int a[n], cnt[n + 10] = {};
	bool d[n + 10] = {};
	for (int i = 0; i < n; i++){
		cin >> a[i];
		cnt[a[i]]++;
	}
	vector <int> v;
	for (int i = 1; i <= n; i++){
		if (cnt[i] == 0)
			v.push_back(i);
	}
	int h = 0;
	for (int i = 0; h < v.size() && i < n; i++){
		if (cnt[a[i]] == 1)
			continue;
		if (a[i] > v[h] || d[a[i]]){
			cnt[a[i]] --;
			a[i] = v[h];
			h++;
		}else{
			d[a[i]] = true;
		}
	}
	cout << v.size() << endl;
	for (int i = 0; i < n; i++)
		cout << a[i] << ' ';
	cout << endl;
}