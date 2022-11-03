#include <bits/stdc++.h>
        
using namespace std;
        
typedef long long ll;
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db long double

const int mod = (int)1e9 + 7;

int mult(int a, int b){
	return a * (ll)b % mod;
}

int bp(int a, int k){
	if (k == 0) return 1;
	if (k % 2 == 1){
		return mult(a, bp(a, k - 1));
	} else {
		int q = bp(a, k / 2);
		return mult(q, q);
	}
}

int n;
map<int, int> was;
int ans = 0;
int fac[1000007];
int invfac[1000007];

int cnk(int a, int b){
	return mult(fac[b], mult(invfac[a], invfac[b - a]));
}

int cnkPlus(int a, int b){
	return cnk(a, a + b - 1);
}

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output1.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    fac[0] = 1;
    for (int i = 1; i < 1000007; i++) fac[i] = mult(fac[i - 1], i);
    invfac[1000006] = bp(fac[1000006], mod - 2);
	for (int i = 1000005; i >= 0; i--) invfac[i] = mult(i + 1, invfac[i + 1]);
	for (int i = 0; i < n; i++){
		int x;
		cin >> x;
		was[x]++;
	}
	was.erase(--was.end());
	int cnt = 0;
	for (auto c : was){
		int add = mult(c.x, c.y);
		add = mult(add, fac[n - cnt - 1]);
		add = mult(add, fac[cnt]);
		add = mult(add, cnkPlus(cnt, n - cnt + 1));
		//cout << add << endl;
		ans = (ans + add) % mod;
		cnt += c.y;
	}
	cout << ans;
}