#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

#define F first
#define S second

const int MOD = 1e9 + 7;//XXX
const int C = 26;//XXX

void add(int &x, int y){
	x += y;
	while (x >= MOD) x -= MOD;
	while (x < 0) x += MOD;
}

int fix(int x){
	while (x >= MOD) x -= MOD;
	while (x < 0) x += MOD;
	return x;
}

int pw(int a, int b){
	int ret = 1;
	while (b){
		if (b & 1)
			ret = 1ll*ret*a%MOD;
		b >>= 1;
		a = 1ll*a*a%MOD;
	}
	return ret;
}

const int MAXN = 2e5 + 10;
const int SQ = 420;

int n;
vector<int> vec[MAXN], sec[MAXN];
int mark[MAXN];

void solve() {
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int t; cin >> t;
        vec[i].resize(t);
        for (int j = 0; j < t; j++) {
            cin >> vec[i][j];
            if (!mp.count(vec[i][j])) {
                sec[mp.size()].clear();
                int temp = mp.size();
                mp[vec[i][j]] = temp;
            }
            vec[i][j] = mp[vec[i][j]];
            sec[vec[i][j]].push_back(i);
        }
    }

    for (int i = 0; i < n; i++)
        if ((int)vec[i].size() >= SQ) {
            fill(mark, mark + n, 0);
            for (int x: vec[i])
                for (int s: sec[x]) {
                    mark[s]++;
                    if (s != i && mark[s] > 1) {
                        cout << i+1 << " " << s+1 << "\n";     
                        return;
                    }
                }
        }
    for (int j = 0; j < (int)mp.size(); j++)
        if ((int)sec[j].size() >= SQ) {
            fill(mark, mark + n, 0);
            for (int s: sec[j])
                mark[s] = 1;
            for (int jj = 0; jj < (int)mp.size(); jj++) {
                if (jj == j) continue;
                int s1 = -1;
                for (int s: sec[jj])
                    if (mark[s]) {
                        if (s1 == -1)
                            s1 = s;
                        else {
                            cout << s1+1 << " " << s+1 << "\n";
                            return;
                        }
                    }
            }
        }
    fill(mark, mark + n, 0);
    int gg = 10;
    for (int i = 0; i < n; i++) 
        if ((int)vec[i].size() < SQ) {
            gg++;
            for (int x: vec[i])
                if ((int)sec[x].size() < SQ)
                    for (int s: sec[x]) {
                        if (mark[s] == gg && s != i) {
                            cout << i+1 << " " << s+1 << "\n";
                            return;
                        }
                        mark[s] = gg;
                    }
        }
    cout << "-1\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//cout << fixed << setprecision(6);
	
	int te = 1;	
	cin >> te;
	for (int w = 1; w <= te; w++){
		//cout << "Case #" << w << ": ";
		solve();
	}
	return 0;
}