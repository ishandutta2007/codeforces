#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define pii pair<int, int>
#define M 1000000007
#define all(a) a.begin(), a.end()
typedef long long ll;

const int maxn = 100100;
int n;
int v[maxn], t[maxn];
ll s[maxn], d[maxn], dd[maxn];

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", v + i);
	for(int i = 1; i <= n; ++i) scanf("%d", t + i), s[i] = t[i] + s[i - 1];
	for(int i = 1; i <= n; ++i){
		int l = i, r = n + 1;
		while(l + 1 < r){
			int d = (l + r) >> 1;
			if(s[d - 1] - s[i - 1] < v[i]) l = d;
			else r = d;
		}
		d[i] += 1;
		d[l] -= 1;

		//printf("%d\n", l);

		dd[l] += min((ll)t[l], v[i] - (s[l - 1] - s[i - 1]));
	}

	for(int i = 1; i <= n; ++i){
		d[i] += d[i - 1];
		//puts("");
		//printf("%I64d %I64d ", d[i], dd[i]);
		printf("%I64d ", d[i] * t[i] + dd[i]);
	}
	
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}