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

map<string, pii> moves;

bool done;
pii acc_move;
void process_response() {
    string move; cin >> move;
    if (move == "Done")
        done = true;
    else {
        auto dir = moves[move];
        acc_move.F += dir.F;
        acc_move.S += dir.S;
    }
}

void query(int a, int b) {
    cout << a << " " << b << endl;
    process_response();
}

void solve() {
    moves["Right"] = {0, 1};
    moves["Left"] = {0, -1};
    moves["Up"] = {-1, 0};
    moves["Down"] = {1, 0};
    moves["Down-Right"] = {1, 1};
    moves["Down-Left"] = {1, -1};
    moves["Up-Left"] = {-1, -1};
    moves["Up-Right"] = {-1, 1};

    int beg_col = 0;
    acc_move = {0, 0};
    done = false;
    int r = 1, c = 1;
    query(r, c);
    while (!done) {
        beg_col++;
        bool failed = false;
        while (!done && !failed) {
            int tc = beg_col + acc_move.S;
            if (tc <= c || r == 8 || c == 8)
                failed = true;
            else if (tc > c + 1)
                query(r, ++c);
            else
                query(++r, c);
        }
        if (!done && r > 1)
            query(r=1, c);
        if (!done && c > 1)
            query(r, c=1);
    }
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