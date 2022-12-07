#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define ll long long
#define M 1000000007
#define all(a) a.begin(), a.end()

int n;
char t[1001000];
int len[100100], bg[100100];
pair<int, int> tag[2001000];
int k[100100];

int main(){
	scanf("%d", &n);
	int maxlen = 0;
	for(int i = 1; i <= n; ++i){
		bg[i] = bg[i - 1] + len[i - 1];
		scanf("%s", t + bg[i]);
		len[i] = strlen(t + bg[i]);
		scanf("%d", k + i);
		for(int j = 1; j <= k[i]; ++j){
			static int xx;
			scanf("%d", &xx); xx--;
			if(len[tag[xx].fi] < len[i]) tag[xx] = mkp(i, 0);
			maxlen = max(maxlen, xx + len[i]);
		}
	}
	auto now = mkp(0, 0);
	for(int i = 0; i < maxlen; ++i){
		if(len[tag[i].fi] > len[now.fi] - now.se) now = tag[i];
		if(!now.fi) putchar('a');
		else putchar(t[bg[now.fi] + now.se]);
		now.se++;
		if(now.se == len[now.fi]) now = mkp(0, 0);
	}
	
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}