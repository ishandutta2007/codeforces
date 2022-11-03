#include <bits/stdc++.h>
					
using namespace std;
			
typedef long long ll;
#define mp make_pair
#define pub push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db long double

int n;
int a[1555];

int main(){
//	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	int cnt = 0;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < i; j++) if (a[j] > a[i]) cnt++;
	}
	int m;
	cin >> m;
	cnt %= 2;
	while(m--){
		int l, r;
		cin >> l >> r;
		l--; r--;
		int len = r - l + 1;
		int val = len / 2;
		val %= 2;
		cnt ^= val;
		if (cnt % 2 == 0) cout << "even\n";
		else cout << "odd\n";
	}
}