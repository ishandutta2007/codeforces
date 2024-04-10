#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first 
#define S second

int main(){
	ios::sync_with_stdio(false);
	int t = 1;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		int fg[n] = {};
		int g[n] = {};
		for (int i = 0 ; i < n; i++){
			int l;
			cin >> l;
			for (int j = 0; j < l; j++){
				int x;
				cin >> x;
				if (fg[i] == 0 && g[x - 1] == 0){
					fg[i] = x;
					g[x - 1] = i + 1;
				}
			}
		}
		int an1 = -1, an2 = -1;
		for (int i = 1; i <= n; i++){
			if (g[i - 1] == 0){
				an2 = i;
				break;
			}
		}
		if (an2 == -1){
			cout << "OPTIMAL\n";
		}else{
			cout << "IMPROVE\n";
			for (int i = 0; i < n; i++){
				if (fg[i] == 0)
					an1 = i + 1;
			}
			cout << an1 << ' ' << an2 << endl;
		}
	}
}