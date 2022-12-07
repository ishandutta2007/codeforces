#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define ll long long
#define pii pair<int, int>
#define M 1000000007
#define all(a) a.begin(), a.end()

const int maxn = 1000005;
int n, m;
char s[maxn];
int y[maxn];
bool tag[maxn];
int p[maxn];
bool ok[maxn];

int main(){
	scanf("%d%d", &n, &m);
	scanf("%s", s + 1);
	int len = strlen(s + 1);
	//reverse(s + 1, s + len + 1);
	int j = 0;
	for(int i = 2; i <= len; ++i){
		while(j && s[j + 1] != s[i]) j = p[j];
		if(s[j + 1] == s[i]) ++j;
		p[i] = j;
	}
	int x = len;
	while(x) ok[len - x] = 1, x = p[x];

	for(int i = 1; i <= m; ++i){
		scanf("%d", y + i);
		tag[y[i]] = 1;
		if(i > 1 && y[i] - y[i - 1] < len){
			if(!ok[y[i] - y[i - 1]]){
				printf("0\n");
#ifndef ONLINE_JUDGE
				system("pause");
#endif
				return 0;
			}
		}
	}

	int now = 0, cnt = n;
	for(int i = 1; i <= n; ++i){
		if(tag[i]) now = len;
		if(now){
			--cnt;
			--now;
		}
	}
	int ans = 1;
	while(cnt--) ans = (ll)ans * 26 % M;
	printf("%d\n", ans);
	
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}