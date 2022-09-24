#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll D[505050], S[505050], K[505050];
ll n, cnt, sum;

void check(ll l, ll r)
{
	if(l > r || l > n || r < 0) return;
	
	K[max(0ll, l)] ++;
	K[min(n, r) + 1] --;
}

int main()
{
	ll i, j, s, k, x, s1, s2;
	
	scanf("%lld", &n);
	
	for(i=0; i<n; i++){
		scanf("%lld", D + i);
		sum += D[i];
	}
	
	sort(D, D + n);
	reverse(D, D + n);
	
	for(i=n-1; i>=0; i--){
		S[i] = S[i + 1] + D[i];
	}
	
	k = 1; s = 0;
	for(j = n-1; j >= 0 && D[j] < k; j --);
	
	if(j >= 0) x = k * (j + 1) + (S[0] - S[n]);
	else x = (S[0] - S[n]);
	s2 = k * (k - 1) + x;
	
	check(max(D[0], s2 - s + 1), n);
	
	for(i=0; i<n; i++){
		s += D[i];
		
		if(j > i) x = k * (j - i) + (S[j + 1] - S[n]);
		else x = (S[i + 1] - S[n]);
		s1 = k * (k - 1) + x;
		
		if(s > s1 + k) check(0, D[i]);
		else check(0, min(D[i], min(k, s - s1 - 1)));
		
		k ++;
		for(; j >= 0 && D[j] < k; j --);
		
		if(j > i) x = k * (j - i) + (S[j + 1] - S[n]);
		else x = (S[i + 1] - S[n]);
		s2 = k * (k - 1) + x;
		
		check(max(D[i + 1], s2 - s + 1), n);
	}
	
	s = 0;
	
	for(i=0; i<=n; i++){
		s += K[i];
		if(!s && (~(i + sum) & 1)){
			cnt ++;
			printf("%d ", i);
		}
	}
	
	if(!cnt) printf("-1\n");
	else printf("\n");
	
	return 0;
}