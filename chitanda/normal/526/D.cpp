#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define ll long long
#define M 1000000007
#define all(a) a.begin(), a.end()

int n, k;
char s[1000100], ans[1000100];
int p[1000100], w[1000100];

int main(){
	//freopen("input.txt", "r", stdin);
	scanf("%d%d", &n, &k);
	scanf("%s", s + 1);
	int j = 0;
	for(int i = 2; i <= n; ++i){
		while(j && s[i] != s[j + 1]) j = p[j];
		if(s[i] == s[j + 1]) ++j;
		p[i] = j;
		w[i] = p[i];
	}
	for(int i = n; i >= 1; --i){
		if(k == 1) { ans[i] = '1'; continue; }
		if(p[i] * 2 >= i){
			int x = w[i]; ll re = (ll)k * x - (ll)(k - 1) * i;
			while(re > i - x) x = p[x], re = (ll)k * x - (ll)(k - 1) * i;
			if(re >= 0) ans[i] = '1';
			else ans[i] = '0';
			w[p[i]] = min(w[p[i]], x);
		}else ans[i] = '0';
	}
	printf("%s", ans + 1);
	
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}