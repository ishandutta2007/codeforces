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

const int MAXN = 7e5 + 10;

int n, mnc[MAXN];
string t, s;
ll ans;
int fen[MAXN];

void add(int v){for (; v<MAXN; v+=v&-v) fen[v]++;}
int get(int v){
	int ret = 0;
	for (; v; v-=v&-v)
		ret += fen[v];
	return ret;
}

int mx[MAXN];
vector<int> vec[MAXN];
int tl[MAXN], tr[MAXN];
void solve() {
	cin >> n >> t;
	for (int i = 0; i < (int)t.size(); i++) {
		if (i) 
			s += '$';
		s += t[i];
	}   

	{
		int st = -1; 
		n = s.size();
		for (int i = 0; i < n; i++) {
			int &x = mnc[i] = 1;
			if (i && i < st+mnc[st]) x = min(mnc[st+st-i], st + mnc[st] - i); 
			while (i - x >= 0 && i + x < n && s[i-x] == s[i+x]) x++;
			if (i == 0 || i+x >= st+mnc[st]) st = i;
		}
	}

	set<int> st;
	memset(tl, -1, sizeof(tl));
	memset(tr, -1, sizeof(tr));
	for (int i = 0; i < n; i++){
		for (auto x: vec[i])
			st.erase(x);
		vec[i].clear();
		if (st.size()) {
			int c = *(st.rbegin());
			tl[i] = i - 2*(i-c);
		}
		st.insert(i);
		vec[i+mnc[i]].push_back(i);
	}
	st.clear();
	for (int i = n-1; ~i; i--){
		for (auto x: vec[i])
			st.erase(x);
		vec[i].clear();
		if (st.size()) {
			int c = *(st.begin());
			tr[i] = i + 2*(c-i);
		}
		st.insert(i);
		if (i-mnc[i] >= 0)
			vec[i-mnc[i]].push_back(i);
	}

	for (int i = 0; i < n; i++){
		for (auto x: vec[i])
			add(x);
		if (i%2 == 0){
			ans += get(tl[i] + 1);
			vec[tr[i]].push_back(i + 1);
		}
	}

	cout << ans << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//cout << fixed << setprecision(6);
	
	int te = 1;	
	//cin >> te;
	for (int w = 1; w <= te; w++){
		//cout << "Case #" << w << ": ";
		solve();
	}
	return 0;
}