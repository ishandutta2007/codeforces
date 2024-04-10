/*	* In the name of GOD
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 1234;
int a[N];
bool f[N];

int32_t main(){
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> a[i], f[i] = false;
		int x = 0, y = 0;
		int a1 = 0, b1 = n - 1;
		int an1 = 0;
		int an2 = 0;
		while (true){
			if (y % 2 == 0){
				int s1 = 0, s3 = 0;
				for (int i = a1; i < n; i++){
					if (f[i])
						break;
					s1 += a[i];
					a1 ++;
					f[i] = true;
					if (s1 > x){
						s3 = x;
						x = s1;
						break;
					}
				}
				if (s1 <= s3)
					break;
				an1 += s1;
			}else{
				int s2 = 0, s4 = 0;
				for (int i = b1; i >= 0; i--){
					if (f[i])
						break;
					s2 += a[i];
					b1 --;
					f[i] = true;
					if (s2 > x){
						s4 = x;
						x = s2;
						break;
					}
				}
				if (s2 <= s4)
					break;
				an2 += s2;
			}
			y++;
		}
		cout << y << ' ' << an1 << ' ' << an2 << '\n';
	}
}