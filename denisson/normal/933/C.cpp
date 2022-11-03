#include <bits/stdc++.h>
                    
using namespace std;
            
typedef long long ll;
#define mp make_pair    
#define pb push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db long double

struct pt{
	db x, y;
	pt() {}
	pt(db x1, db y1) { x = x1; y = y1; }
	pt operator- (pt nxt) { return pt(x - nxt.x, y - nxt.y); }
	pt operator+ (pt nxt) { return pt(x + nxt.x, y + nxt.y); }
	db len() { return sqrt(x * x + y * y); }
	db sqLen() { return x * x + y * y; }
	pt rotate(db ang) { return pt(x * cos(ang) + y * sin(ang), -x * sin(ang) + y * cos(ang)); }
	pt norm(db val) { return pt(x * val / len(), y * val / len()); }
};

int n;
pt a[3];
ll r[3];

vector<pt> t;

void add(pt a){
	for (int i = 0; i < t.size(); i++) if ((t[i] - a).len() < 1e-6) return;
	//cout << a.x << ' ' << a.y << endl;
	t.pb(a);
}

void cross(int v1, int v2){
	if (r[v1] < r[v2]) swap(v1, v2);
	db val = (a[v1] - a[v2]).sqLen();
	if (val <= r[v1] * r[v1]){
		if (val < (r[v1] - r[v2]) * (r[v1] - r[v2])) return;
		db ang = acos((r[v1] * r[v1] - r[v2] * r[v2] - val) / (db)(-2 * r[v2] * (a[v1] - a[v2]).len()));
		auto v = a[v1] - a[v2];
		add(a[v2] + (v.rotate(ang).norm(r[v2])));
		add(a[v2] + (v.rotate(-ang).norm(r[v2])));
	} else {	
		if (val > (r[v1] + r[v2]) * (r[v1] + r[v2])) return;
		db ang = acos((r[v2] * r[v2] - r[v1] * r[v1] - val) / (db)(-2 * r[v1] * (a[v1] - a[v2]).len()));
		auto v = a[v2] - a[v1];
		add(a[v1] + (v.rotate(ang)).norm(r[v1]));
		add(a[v1] + (v.rotate(-ang)).norm(r[v1]));
		//cout << "===" << v1 << ' ' << v2 << endl;
	}
}

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++){
    	cin >> a[i].x >> a[i].y >> r[i];
    }
    for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) cross(i, j);
    if (t.size() == 0) cout << n + 1, exit(0);
    int ans = -t.size();
    for (int i = 0; i < n; i++){
    	int cnt = 0;
    	for (int j = 0; j < t.size(); j++){
    		if (abs(r[i] - (t[j] - a[i]).len()) < 1e-6) cnt++;
    	}
    	//cout << "===" << i << ' ' << cnt << endl;
    	if (cnt == 0) ans += 1;
    	else ans += cnt;
    }
    cout << ans + 2;
}