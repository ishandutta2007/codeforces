#include<bits/stdc++.h>
using namespace std;
char _;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template <typename t> void scan (t& x) {do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0);}
template <typename t, typename ...r> void scan (t& x, r&... xs) {scan(x); scan(xs...);}
const int MAXN = 1e5+2;
int arr[MAXN];
map<int,int> freq;
map<int,int> nw;
int main () {
	int n,a,cnt = 0, ans = INT_MAX;
	scanf ("%d",&n);
	for (int i = 0; i < n; i++) {
		scanf ("%d",&arr[i]);
		++freq[arr[i]];
		if (freq[arr[i]] == 2) ++cnt;
	}
	if(!cnt) return !printf ("0\n");
	int ocnt = cnt;
	for (int l = 0; l < n; l++) {
		nw = freq; cnt = ocnt;
		for (int r = l; r < n; r++) {
			--nw[arr[r]];
			if (nw[arr[r]] == 1) --cnt;
			if (cnt <= 0) ans = min(ans,r-l+1);
		}
	}
	printf ("%d\n",ans);
	return 0;
}