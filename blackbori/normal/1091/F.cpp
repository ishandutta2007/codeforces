#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll L[101010];
char S[101010];
ll n, a, b, c, d, s, ans;

int main()
{
	ll i;
	
	scanf("%lld", &n);
	
	for(i=0; i<n; i++){
		scanf("%lld", L + i);
	}
	
	scanf("%s", S);
	
	for(i=0; i<n; i++){
		if(S[i] == 'W') c = 1, a += 2 * L[i];
		else if(S[i] == 'G') d = 1, b += 2 * L[i];
		s -= L[i];
		ans += L[i];
		
		if(s < 0){
			if(-s <= a){
				ans += 1 * (-s);
				a += s;
				s = 0;
			}
			else{
				ans += 1 * a;
				s += a;
				a = 0;
				
				if(-s <= b){
					ans += 2 * (-s);
					b += s;
					s = 0;
				}
				else{
					ans += 2 * b;
					s += b;
					b = 0;
				}
			}
		}
		
		if(s < 0){
			if(c){
				ans += 3 * (-s);
				s = 0;
			}
			else if(d){
				ans += 5 * (-s);
				s = 0;
			} 
		}
	}
	
	printf("%lld\n", ans);
	
	return 0;
}