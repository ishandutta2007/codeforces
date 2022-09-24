#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair <ll, ll> pll;

ll A[7070], B[7070];
pll P[7070];
bool chk[7070];
ll n, ans;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll i, j;
	
	cin >> n;
	
	for(i=0; i<n; i++){
		cin >> A[i];
	}
	
	for(i=0; i<n; i++){
		cin >> B[i];
		P[i] = pll(A[i], B[i]);
	}
	
	sort(P, P + n);
	reverse(P, P + n);
	
	for(i=1; i<n; i++){
		if(P[i].first == P[i - 1].first){
			chk[i] = 1;
			chk[i - 1] = 1;
		}
	}
	
	for(i=0; i<n; i++){
		for(j=0; j<i; j++){
			if(chk[j] && (P[i].first & P[j].first) == P[i].first){
				chk[i] = 1; break;
			}
		}
		
		if(chk[i]) ans += P[i].second;
	}
	
	printf("%lld\n", ans);
	
	return 0;
}