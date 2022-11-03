#include <bits/stdc++.h>
                     
using namespace std;
             
typedef long long ll;
#define mp make_pair
#define pub push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db double

int n;
int r;
int x[1111];
db y[1111];

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> r;
	for (int i = 0; i < n; i++) cin >> x[i];
	y[0] = r;
	for (int i = 1; i < n; i++){
		db ma = r;
		for (int j = 0; j < i; j++){
			if (abs(x[i] - x[j]) > 2 * r) continue;
			ma = max(ma, y[j] + sqrt(4 * r * (db)r - (x[i] - x[j]) * (db)(x[i] - x[j])));
		}
		y[i] = ma;
	}
	cout.precision(10);
	for (int i = 0; i < n; i++){
		cout << fixed << y[i] << ' ';	
	}
}