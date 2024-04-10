#include <bits/stdc++.h>
#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
using namespace std;

const int nax = 200005, mod = 1e9 + 7, inf = 1e9;

int pot(int a, int b){
	int res = 1;
	while(b)
	{
		if(b & 1)
			res = (ll) res * a % mod;
		a = a * a % mod;
		b /= 2;
	}
	return res;
}

int n;
int t[nax];
int a, b, c;


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 1; n >= i; ++i)
	{
		cin >> a;
		if(a == 1)
			++b;
		else
			++c;
	}
	if(b >= 1 && c >= 1)
	{
		cout << 2 << " " << 1 << " ";
		for(int i = 1; c - 1 >= i; ++i)
			cout << 2 << " ";
		for(int i = 1; b - 1 >= i; ++i)
			cout << 1 << " ";
		return 0;
	}
	else
	{
		for(int i = 1; b >= i; ++i)
			cout << 1 << " ";
		for(int i = 1; c >= i; ++i)
			cout << 2 << " ";
	}
	
	return 0;
}