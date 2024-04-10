#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db long double
#define sz(a) (int)a.size()

ll n, m;
ll a[100007];
ll w1, w2;
ll ww = 0;

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    int uk = 0;
	for (int i = 0; i < n; i++){
		while(uk + 1 < n && a[uk + 1] - a[i] <= m) uk++;
		if (i + 2 > uk) continue;
		ll s1 = a[uk] - a[i + 1];
		ll s2 = a[uk] - a[i];
		if (ww == 0){
			w1 = s1;
			w2 = s2;
			ww = 1;
		} else {
			if (s1 * w2 > w1 * s2){
				w1 = s1;
				w2 = s2;
			}
		}
	}
	if (ww == 0) cout << -1;
	else {
		cout.precision(10);
		cout << fixed << w1 / (db)w2;
	}
}