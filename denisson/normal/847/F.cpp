#include <bits/stdc++.h>
	  
using namespace std;
	  
typedef long long ll;
#define mp make_pair
#define pub push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db double

int n, k, m, a;
int cnt[111];
int last[111];

int main() { 
	srand('D' + 'E' + 'N' + 'I' + 'S' + 'S' + 'O' + 'N' + time(NULL));
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//freopen("cpr.in", "r", stdin);
	//freopen("cpr.out", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k >> m >> a;
	for (int i = 0; i < n; i++) last[i] = -1;
	for (int i = 0; i < a; i++){
		int x;
		cin >> x;
		x--;
		cnt[x]++;
		last[x] = i;
	}

	vector<pair<pair<int, int>, int> > t;
	for (int i = 0; i < n; i++) t.pub(mp(mp(cnt[i], -last[i]), i));
	sort(all(t));
	reverse(all(t));

	/*for (auto c : t){
		cout << c.x.x << ' ' << c.x.y << endl;
	}*/

	int ost = m - a;
	for (int i = 0; i < n; i++){
		pair<int, int> my = mp(cnt[i], -last[i]);
		if (my.x != 0){
			int need = 0;
			int cc = 0;
			for (int j = 0; j < t.size(); j++) if (t[j].y != i){
				auto now = t[j].x;
				while(now < my){
					now.x++;
					now.y = -(a + need);
					need++;
				}
				cc++;
				if (cc == k) break;
			}
			if (cc < k || need > ost){
				cout << 1 << ' ';
				continue;
			}
		}
		if (ost > 0){
			my.x += ost;
			my.y = -(m - 1);
		}

		int cc = 0;
		for (int j = 0; j < t.size(); j++) if (t[j].y != i){
			if (t[j].x > my) cc++;
		}

		if (my.x != 0 && cc <= k - 1){
			cout << 2 << ' ';
			continue;
		}

		cout << 3 << ' ';
	}
}