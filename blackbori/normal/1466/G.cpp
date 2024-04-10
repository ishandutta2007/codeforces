#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pll = pair <ll, ll>;

const ll mod = 1e9 + 7;

string S, T, K[111];
ll _2[101010], _2_[101010];
ll C[101010][26];
bool M[101010];
int F[111];
int n, sn, tn;

ll query(string &Q, int p, int d)
{
	if(Q.empty()){
		if(d - p + 1 < 0) return 0;
		return _2[d - p + 1];
	}
	if(p > d) return 0;
	else if(Q.size() == 1){
		int t = Q[0] - 'a';
		return (C[p][t] + mod - C[d + 1][t]) * _2_[tn - 1 - d] % mod;
	}

	string L, R; int i;
	bool fl = 1, fr = 1;
	for(i = 0; i < Q.size(); i ++){
		if(i & 1){
			L.push_back(Q[i]);
			if(Q[i] != T[p]) fl = 0;
		}
		else{
			R.push_back(Q[i]);
			if(Q[i] != T[p]) fr = 0;
		}
	}

	ll a = 0;
	if(fr) a += query(L, p + 1, d);
	if(fl) a += query(R, p + 1, d);
	if(a >= mod) a -= mod;

	return a;
}

void tc()
{
	string Q;
	int q, i, j, t; ll a;

	cin >> n >> q >> S >> T;

	sn = S.size(); tn = T.size();

	_2[0] = 1; _2_[0] = 1;
	for(i = 1; i <= tn; i ++){
		_2[i] = (_2[i - 1] * 2) % mod;
		_2_[i] = (_2_[i - 1] * (mod + 1 >> 1)) % mod;
	}

	for(i = tn - 1; i >= 0; i --){
		for(j = 0; j < 26; j ++){
			C[i][j] = C[i + 1][j];
		}
		t = T[i] - 'a';
		C[i][t] = (C[i][t] + _2[tn - 1 - i]) % mod;
	}

	for(; q --; ){
		cin >> t >> Q; int qn = Q.size();

		for(i = 0, a = 0; i <= sn; i ++){
			string K;
			int l = i; bool f = 1;
			for(j = 0; f && j < qn; j ++){
				if(l < sn){
					if(S[l] != Q[j]) f = 0;
					l ++;
				}
				else{
					K.push_back(Q[j]);
					l = 0;
				} 
			}
			if(f) a += query(K, 0, t - 1);
		}
		cout << a % mod << "\n";
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
/*
	cin >> t;
/*/
	t = 1;
//*/
	for(; t --; ) tc();

	return 0;
}