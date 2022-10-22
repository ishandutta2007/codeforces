#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 1e7 + 10;

int n, k;
ll cnt[MAXN], tt[MAXN];

int main(){
	scanf("%d %d", &n, &k);
	int mn = 1e9;
	for (int i = 0; i < n; i++){
		int x;	scanf("%d", &x);
		cnt[x]++;
	}
	
	ll cur = 0;
	for (int i = MAXN - 1; i; i--){
		cur += cnt[i];
		cur -= tt[i];

		ll cc = cnt[i];
		cnt[i>>1] += cc;
		cnt[(i+1)>>1] += cc;
		tt[(i+1)>>1] += cc;
		
		mn = min(mn,i);
		if (cur >= k){
			printf("%d\n", mn);
			return 0;
		}
	}

	printf("-1\n");
	return 0;
}