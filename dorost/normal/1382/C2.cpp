/* 	* In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 101234;
int rev[N];
int flip;

char f(char c){
	if (flip == 1){
		if (c == '1')
			return '0';
		else
			return '1';
	}
	return c;
}

ll rnd(){
	return (ll)rand() * rand();
}

int32_t main(){
	srand (time (NULL));
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--){
		int n;
		string a, b;
		cin >> n >> a >> b;
		vector <int> v;
		flip = 1;
		string x = a;
		if (n > 100){
			for (int i = 0; i < 10; i++){
				int x = (ll)rnd() % n;
				v.push_back(x + 1);
				for (int j = 0; j <= x; j++){
					a[j] = f(a[j]);
				}
				reverse(a.begin(), a.begin() + x + 1);
			}
		}
		for (int i = 0; i < n; i++)
			rev[i] = i;
		flip = 0;
		int cnt = 0;
		for (int i = n - 1; i >= 0; i--){
			if (a[i + cnt] != b[i]){
				if (a[cnt] != a[i + cnt]){
					v.push_back(1);
					if (a[cnt] == '1')
						a[cnt] = '0';
					else
						a[cnt] = '1';
				}
				if (i == 0){
					v.push_back(1);
					break;
				}
				v.push_back(i + 1);
				v.push_back(i);
				cnt++;
			}
		}
		a = x;
		if (v.size() > 2 * n){
			v = {};
			for (int i = n - 1; i >= 0; i--){
				if (a[i] != b[i]){
					if (a[0] != a[i]){
						v.push_back (1);
						if (a[0] == '0')
							a[0] = '1';
						else
							a[0] = '0';
					}
					v.push_back(i + 1);
					for (int j = 0; j <= i; j++){
						if (a[j] == '0')
							a[j] = '1';
						else
							a[j] = '0';
					}
					reverse (a.begin(), a.begin() + i + 1);
					if (a == b)
						break;
				}
			}
		}
		cout << v.size() << ' ';
		for (int i = 0; i < v.size(); i++){
			cout << v[i] << ' ';
		}
		cout << endl;
	}
}