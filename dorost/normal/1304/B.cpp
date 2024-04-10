#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int main(){
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int n , m;
	cin >> n >> m;
	string s[n];
	for (int i = 0; i < n; i++){
		cin >> s[i];
	}
	int f[n];
	for (int i = 0; i < n; i++){
		f[i] = -1;
	}
	for (int i = 0; i < n; i++){
		for (int j = i; j < n; j++){
			string a = s[i], b = s[j];
			reverse(a.begin(), a.end());
			if (a == b){
				f[i] = j;
				f[j] = i;
				break;
			}
		}
	}	
	int ans = 0;
	string g, an;
	for (int i = 0; i < n; i++){
		if (f[i] == i){
			g = s[i];
		}
		if (f[i] > i){
			an += s[i];
		}
	}
	string sa = an + g;
	reverse(an.begin(), an.end());
	sa += an;
	cout << sa.size() << endl;
	cout << sa;
}