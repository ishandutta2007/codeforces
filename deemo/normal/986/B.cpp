#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 1e6 + 10;

ll fen[MAXN];

void add(int v){for (; v<MAXN; v+=v&-v) fen[v]++;}
ll get(int v){
	int ret = 0;
	for (; v; v-=v&-v)
		ret += fen[v];
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	ll ans = 0;
	for (int i = 0; i < n; i++){
		int x; cin >> x;
		ans += i - get(x);
		add(x);
	}
	if (n%2 == 1){
		if (ans&1)
			cout << "Petr\n";
		else
			cout << "Um_nik\n";
	}
	else{
		if (ans&1)
			cout << "Um_nik\n";
		else
			cout << "Petr\n";
	}
	return 0;
}