#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
#define ll long long

int power(int b, int a = 10){
	int res = 1;
	for(; b; b >>= 1, a = (ll)a * a % M)
		if (b & 1) res = (ll)res * a % M;
	return res;
}
struct node{
	int x, y;
	node () {}
	node(int x, int y) : x(x), y(y) {}
	node(string &s){
		x = s.size(); y = 0;
		for(int i = 0; i < x; ++i)
			y = ((ll)y * 10 + (s[i] - '0')) % M;
	}
	node operator + (const node &a){
		return node((x + a.x) % (M - 1), ((ll)y * power(a.x) + a.y) % M);
	}
	node operator ^ (string &s){
		int re = 0;
		for(int i = 0; i < s.size(); ++i)
			re = ((ll)re * 10 + (s[i] - '0')) % (M - 1);
		if(!x) return node(0, (ll)y * re % M);
		int tx = power(x);
		int tmp = (ll)(power(re, tx) + M - 1) * power(M - 2, tx + M - 1) % M * y % M;
		return node((ll)re * x % (M - 1), tmp);
	}
};

string get(string &s, int &i){
	string res;
	while(isdigit(s[i])) res += s[i++];
	return res;
}

int del(string &L, string &R){
	int l = L.size(), re = 0;
	for(int i = 0; i < l; ++i)
		re = ((ll)re * 10 + (R[i] - L[i])) % (M - 1);
	return re;
}

node range(string &L, string &R){
	if(L.size() == R.size()){
		int nL = node(L).y, nR = node(R).y;
		int x = power(L.size());
		int z = (del(L, R) + 1) % (M - 1);
		int tmp = ((ll)nL * power(z, x) - nR + M) % M * power(M - 2, x + M - 1) % M;
		(tmp += (ll)(power(z, x) + M - x) * power(M - 2, (ll)(x + M - 1) * (x + M - 1) % M) % M) %= M;
		return node(int((ll)L.size() * z % (M - 1)), tmp);
	}else{
		string LM = string(L.size(), '9');
		string RM = "1" + string(R.size() - 1, '0');
		
		node res = range(L, LM);
		int nL = power(L.size()), nR = ((ll)nL * 10 + M - 1) % M;
		int x = power(L.size() + 1);
		int z = 9; for(int i = 1; i <= L.size(); ++i) z = (ll)z * 10 % (M - 1);
		
		for(int i = L.size() + 1; i < R.size(); ++i){
			int tmp = ((ll)nL * power(z, x) - nR + M) % M * power(M - 2, x + M - 1) % M;
			(tmp += (ll)(power(z, x) + M - x) * power(M - 2, (ll)(x + M - 1) * (x + M - 1) % M) % M) %= M;
			res = res + node((ll)i * z % (M - 1), tmp);
			nL = (ll)nL * 10 % M, nR = ((ll)nL * 10 + M - 1) % M;
			x = (ll)x * 10 % M;
			z = (ll)z * 10 % (M - 1);
		}

		return res + range(RM, R);
	}
}

node work(string &s, int &i){
	node tmp(0, 0);
	string num = "";
	int l = s.size();
	while(i < l){
		if(isdigit(s[i])) num = get(s, i);
		if(i == l) break;
		char ty = s[i++];
		if(ty == ')') return tmp + node(num);
		if(ty == '(') tmp = tmp + (work(s, i) ^ num);
		if(ty == '+') tmp = tmp + node(num);
		if(ty == '-'){
			string num2 = get(s, i);
		  tmp = tmp + range(num, num2);
		}
		num.clear();
	}
	return tmp + node(num);
}

int main(){
	//freopen("x.in", "r", stdin);
	//freopen("x.out", "w", stdout);
	string s;
	cin >> s;
	int i = 0;
	printf("%d\n", work(s, i).y);
	return 0;
}