#include <bits/stdc++.h>
                   
using namespace std;
           
typedef long long ll;
#define mp make_pair
#define pub push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db long double

struct st{
	int x, y, z;
};

int n, g[3];
st a[500007];
vector<int> d[500007];
set<pair<int, int> > se;
ll ans = 0;
ll val = 0;

void add(int y, int z){
	auto it = se.upper_bound(mp(y, 1e9)); it--;
	if (y == 1 && z == 1 && it == se.begin()){
	}
	if (it->y >= z) return;
	vector<pair<int, int> > t;
	while(1){
		if (it->y > z) break;
		t.pub(*it);
		if (it == se.begin()) break;
		it--;
	}

	//cout << "===" << y << ' ' << z << ' ' << t.size() << ' ' << t[0].x << ' ' << t[0].y << endl;

	for (int i = 0; i < t.size(); i++){
		if (i == 0){
			val -= (y - t[i].x + 1) * (ll)(z - t[i].y);
			auto now = se.find(t[i]);
			now++;
			if (now == se.end()){
				if (y != g[1]) se.insert(mp(y + 1, t[i].y));
			} else {
				if (now->x > y + 1) se.insert(mp(y + 1, t[i].y));
			}
		} else {	
			val -= (t[i - 1].x - t[i].x) * (ll)(z - t[i].y);
		}
		se.erase(t[i]);
	}

	se.insert(mp(t.back().x, z));
}

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output1.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    se.insert(mp(1, 0));
    cin >> n >> g[0] >> g[1] >> g[2];
    val = g[1] * (ll)g[2];
    for (int i = 0; i < n; i++) cin >> a[i].x >> a[i].y >> a[i].z;
   	for (int i = 0; i < n; i++) d[a[i].x].pub(i);
	for (int i = 0; i < n; i++) add(a[i].y, a[i].z);

	//for (auto c : se) cout << c.x << ' ' << c.y << endl;

	//cout << val << endl;

	for (int i = g[0]; i >= 1; i--){
		for (int v : d[i]){
			add(a[v].y, g[2]);
			add(g[1], a[v].z);
		}
		ans += val;
	}
	cout << ans;
}