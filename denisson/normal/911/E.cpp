#include <bits/stdc++.h>
					
using namespace std;
			
typedef long long ll;
#define mp make_pair
#define pub push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db long double

int n, k;
int st[200007];
int uk = 0;
int dd[200007];

int main(){
	//freopen("input.txt", "w", stdout);
	//cout << 200000 << ' ' << 2000 << endl;
	//for (int i = 200000; i > 0; i -= 100) cout << i << endl;;
	//	exit(0);
//	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;
	int now = 1;
	set<int> se;
	for (int i = 0; i < n; i++) se.insert(i + 1);
	for (int i = 0; i < k; i++){
		int x;
		cin >> x;
		dd[i] = x;
		se.erase(x);
		if (x == now){
			now++;
		} else {
			if (uk == 0){
				st[uk] = x;
				uk++;
			} else {
				if (x > st[uk - 1]) cout << -1, exit(0);
				st[uk] = x;
				uk++;
			}
		}
		while(uk != 0 && st[uk - 1] == now){
			uk--;
			now++;
		}
	}
	for (int i = 0; i < k; i++) cout << dd[i] << ' ';
	while(1){
		if (uk == 0){
			vector<int> tt;
			for (int x : se) tt.pub(x);
			reverse(all(tt));
			for (int x : tt) cout << x << ' ';
			exit(0);
		} else {
			auto it = se.upper_bound(st[uk - 1]);
			if (it == se.begin()) exit(0);
			int x = *(--it);
			se.erase(x);
			cout << x << ' ';
			if (x == now){
				now++;
			} else {
				if (uk == 0){
					st[uk] = x;
					uk++;
				} else {
					if (x > st[uk - 1]) cout << -1, exit(0);
					st[uk] = x;
					uk++;
				}
			}
			while(uk != 0 && st[uk - 1] == now){
				uk--;
				now++;
			}
		}
	}
}