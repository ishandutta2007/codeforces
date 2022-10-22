//Everything's a mess..

#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<utility>

using namespace std;

typedef long long ll;

#define F first
#define S second

const ll MAXN = 3e5 + 10;

ll n, m, pos[MAXN];
char dir[MAXN];
ll tm;
pair<ll, char>	sec[MAXN];
ll gec[MAXN];
map<ll, ll>	mp;

void solve(){
	ll cur = 0;
	ll tot = 2LL * tm;
	for (ll i = 1; i < n; i++)
		if (sec[0].S != sec[i].S){
			ll dis = (sec[0].S == 'R'?sec[i].F - sec[0].F:m - (sec[i].F - sec[0].F));
			ll temp = tot;
			temp -= dis;
			if (temp >= 0){
				if (sec[0].S == 'R'){
					cur = (cur + 1) % n;
					cur = (cur + temp/m) % n;
				}
				else{
					cur = (cur - 1 + n) % n;
					cur = ((cur - temp/m) % n + n) % n;
				}
			}
		}
	
	for (ll i = 0; i < n; i++)
		gec[i] = (sec[i].S == 'R'?(sec[i].F + tm) % m:((sec[i].F-tm) % m + m) % m);
	ll temp = gec[0];
	sort(gec, gec + n);
	int p = 0;
	while (gec[p] != temp)	p++;
	if (sec[0].S == 'R' && p + 1 < n && gec[p + 1] == gec[p])	p++;

	for (ll i = 0; i < n; i++, cur = (cur + 1) % n, p = (p + 1) % n)
		mp[sec[cur].F] = gec[p];
}

int main(){
	scanf("%I64d %I64d %I64d", &n, &m, &tm);
	for (ll i = 0; i < n; i++)	
		scanf("%I64d %s", &pos[i], &dir[i]), pos[i]--, sec[i] = {pos[i], dir[i]};
	sort(sec, sec + n);
	solve();
	for (ll i = 0; i < n; i++)
		printf("%I64d ", mp[pos[i]] + 1);
	printf("\n");
	return 0;
}