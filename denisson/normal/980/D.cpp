#include <bits/stdc++.h>
//#pragma comment(linker, /STACK:36777216)
		   
using namespace std;
		   
typedef long long ll;
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db long double

int n;
int a[5005];
int ans[5005];
int ff[5005];

map<int, vector<int> > dd;

int main(){
//	freopen("input.txt", "r", stdin);
	//freopen("output1.txt", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++){
		int val = abs(a[i]);
		int uk = 2;
		int tmp = 1;
		while(1){
			if (uk * uk > val) break;
			int cc = 0;
			while(val % uk == 0){
				cc++;
				val /= uk;
			}
			if (cc % 2 == 1) tmp *= uk;
			uk++;
		}
		tmp *= val;
		if (a[i] < 0) tmp = -tmp;
		a[i] = tmp;
		dd[a[i]].pb(i);
	}

	for (auto c : dd){
		for (int i = 0; i < c.y.size(); i++){
			if (i == 0) ff[c.y[i]] = -1;
			else ff[c.y[i]] = c.y[i - 1];
		}
	}



	for (int i = 0; i < n; i++){
		int cnt = 0;
		for (int j = i; j < n; j++){
			if (a[j] != 0){
				if (ff[j] < i) cnt++;
			}
			ans[max(cnt, 1)]++;
		}
	}

	for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
}