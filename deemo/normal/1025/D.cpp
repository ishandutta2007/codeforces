#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 700 + 10;

int n, a[MAXN];
bool okk[MAXN][MAXN], d[MAXN][MAXN][2];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	n += 2;
	a[0] = a[n-1] = 1;
	for (int i = 1; i < n-1; i++) cin >> a[i];
	
	for (int i = 1; i < n-1; i++) {
		d[i][i+1][0] = __gcd(a[i], a[i-1])>1?true:false;
		d[i][i+1][1] = __gcd(a[i], a[i+1])>1?true:false;
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (__gcd(a[i], a[j]) > 1)
				okk[i][j] = true;

	for (int ln = 2; ln <= n-2; ln++){
		for (int l = 1; l + ln <= n-1; l++){
			bool fl = false;
			bool tl = 0, tr = 0;
			for (int ind = l; ind < l + ln; ind++) {
				bool ok = true;
				if (ind > l && !d[l][ind][1]) ok = false;
				if (ind < l + ln - 1 && !d[ind+1][l + ln][0]) ok = false;
				if (ok) {
					fl = true;
					tl |= okk[l-1][ind];
					tr |= okk[ind][l+ln];
				}
			}
			if (fl) {
				d[l][l+ln][0] = tl, d[l][l+ln][1] = tr;
				if (l == 1 && ln == n-2){
					cout << "Yes\n";
					return 0;
				}
			}
		}
	}

	cout << "No\n";
	return 0;
}