

//be naame khodaa
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
#define F first
#define S second
#define pb push_back

inline int in(){ int x, y; y = scanf("%d", &x); return x; }

vector <char> alpha;

int cnt[1005];
string s[4*100*1000 + 5];

int main(){
	for (char c = 'a'; c <= 'z'; c++) alpha.pb(c);
	for (char c = 'A'; c <= 'Z'; c++) alpha.pb(c);
	for (char c = '0'; c <= '9'; c++) alpha.pb(c);
	int n = in();
	string S;
	cin >> S;
	int odd = 0;
	for (char c : S)
		cnt[c]++;
	for (char c : alpha)
		odd += (cnt[c]%2);
	for (int k = 1; k <= n; k++){
		if (n%k == 0 && (n/k)%2*k >= odd){
			int l = n/k;
			for (int i = 0; i < k; i++){
				s[i] = "";
				for (int j = 0; j < l; j++)
					s[i] += ' ';
			}
			int pairIt = 0, midIt = 0, pairIt2 = 0;
			for (char c : alpha){
				if (cnt[c]%2){
					s[midIt++][l/2] = c;
					cnt[c]--;
				}
				while (cnt[c]){
					while (pairIt < k && pairIt2 >= l/2){
						pairIt++;
						pairIt2 = 0;
					}
					if (pairIt == k) break;
					s[pairIt][pairIt2] = s[pairIt][l-1-pairIt2] = c;
					cnt[c] -= 2;
					pairIt2++;
				}
				while (cnt[c]){
					s[midIt++][l/2] = c;
					cnt[c]--;
				}
			}
			cout << k << '\n';
			for (int i = 0; i < k; i++)
				cout << s[i] << ' ';
			cout << '\n';
			return 0;
		}
	}
	return 0;
}