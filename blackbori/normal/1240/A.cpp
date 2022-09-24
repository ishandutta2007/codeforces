#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll P[202020];
ll n, x, y, a, b, k;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll q, i, s, s1, s2, s3;
	
	cin >> q;
	
	for(; q--; ){
		cin >> n;
		
		for(i=0; i<n; i++){
			cin >> P[i];
		}
		
		sort(P, P + n);
		reverse(P, P + n);
		
		cin >> x >> a >> y >> b >> k;
		
		if(x < y) swap(x, y), swap(a, b);
		
		s = s1 = s2 = s3 = 0;
		
		for(i=1; i<=n; i++){
			if(i % a == 0 && i % b == 0){
				s += P[s1] / 100 * y + P[s1 + s2] / 100 * (x - y) + P[s1 + s2 + s3] / 100 * y;
				s1 ++;
			}
			else if(i % a == 0){
				s += P[s1 + s2] / 100 * (x - y) + P[s1 + s2 + s3] / 100 * y;
				s2 ++;
			}
			else if(i % b == 0){
				s += P[s1 + s2 + s3] / 100 * y;
				s3 ++;	
			}
			
			if(s >= k) break;
		}
		
		if(i > n) cout << "-1\n";
		else cout << i << "\n";
	}
	
	return 0;
}