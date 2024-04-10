#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

char S[1010101];
ll L[1010101], R[1010101];
ll n, ans;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll i, s;
	
	cin >> S;
	
	n = strlen(S);
	
	for(i=1, s=0; i<n; i++){
		if(S[i] == 'v' && S[i - 1] == 'v') s ++;
		L[i] = s;
	}
	
	
	for(i=n-2, s=0; i>=0; i--){
		if(S[i] == 'v' && S[i + 1] == 'v') s ++;
		R[i] = s;
	}
	
	for(i=1; i<n-1; i++){
		if(S[i] == 'o'){
			ans += L[i - 1] * R[i + 1];
		}
	}
	
	cout << ans << "\n";
	
	return 0;
}