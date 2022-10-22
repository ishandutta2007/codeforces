#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 2e5 + 10;

int n, a[MAXN], par[MAXN], d[MAXN];
map<int, int> mp;

void show(int ind){
	if (~par[ind])
		show(par[ind]);
	cout << ind+1 << " ";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	memset(par, -1, sizeof(par));
	for (int i = 0; i < n; i++){
		cin >> a[i];
		if (mp.count(a[i] - 1)){
			d[i] = d[mp[a[i]-1]] + 1;
			par[i] = mp[a[i]-1];
		}
		else
			d[i] = 1;

		mp[a[i]] = i;
	}

	int mx = 0;
	for (int i = 0; i < n; i++) mx = max(mx, d[i]);
	
	cout << mx << "\n";
	for (int i = 0; i < n; i++)
		if (mx == d[i]){
			show(i);
			cout << "\n";
			break;
		}
	return 0;
}