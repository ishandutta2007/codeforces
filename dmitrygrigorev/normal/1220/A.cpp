#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

int main(){
#ifdef LOCAL
	freopen("H_input.txt", "r", stdin);
	//freopen("J_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int z = 0, o = 0;
	string s;
	cin >> s;
	for (int i=0;i<n;++i){
		if (s[i] == 'z') z++;
		if (s[i] == 'n') o++;
	}
	for (int i=0; i < o; ++i) cout << 1 << " ";
	for (int i=0; i < z; ++i) cout << 0 << " ";
}