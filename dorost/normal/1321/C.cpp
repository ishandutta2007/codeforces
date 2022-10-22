#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

signed main(){
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int n, ans = 0;
	cin >> n;
	string s;
	cin >> s;
	bool f[n];
	bool x = true;
	string t;
	while (x){
		t = s;
		char mx = '\0';
		int an = -1;
		for (int i = 0; i < t.size(); i++){
			if ((t[i - 1] == t[i] - 1 || t[i + 1] == t[i] - 1 || t[i - 1] == t[i] - 1  || t[i + 1] == t[i] - 1) && t[i] >= mx){
				mx = t[i];
				an = i;
			}
		}
		if (an == -1){
			break;
		}else{
			ans ++;
			s = "";
			for (int i = 0; i < t.size(); i++){
				if (i != an)
					s += t[i];
			}
		}
		cerr << s << ' ' << an << endl;
	}
	cout << ans;
}