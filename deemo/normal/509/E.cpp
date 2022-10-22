#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>

using namespace std;

typedef long double ld;
typedef long long ll;

const int MAXN = 5e5 + 20;

int n;
string s;
int m1[MAXN], m2[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(12);
	cin >> s;	 n = s.size();

	ll c = 0;
	for (int i = 0; i < n; i++)
		if (s[i] == 'I' || s[i] == 'E' || s[i] == 'A' || s[i] == 'O' || s[i] == 'U' || s[i] == 'Y'){
			int sz = min(i + 1, n - i);
			m1[sz - 1]++;
			m2[n - sz]++;
			c++;
		}

	ld sum = 0;
	ll c2 = 0, cur = 0;
	for (int i = n; i; i--){
		c -= m2[i];//ina ezafeh mishan
		c2 += m1[i];//ina kam mishan
		cur += c;
		cur -= c2;
		
		sum += ld(cur)/ ld(i);
	}
	cout << sum << "\n";
	return	0;
}