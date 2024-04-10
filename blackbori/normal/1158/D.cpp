#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair <ll, ll> pll;

pll P[2020];
ll K[2020];
string S;
ll n;

ll ccw(pll pa, pll pb, pll pc)
{
	return (pa.first * pb.second + pb.first * pc.second + pc.first * pa.second)
		- (pa.second * pb.first + pb.second * pc.first + pc.second * pa.first);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll i, j, x, y;
	
	cin >> n;
	
	for(i=1; i<=n; i++){
		cin >> x >> y;
		P[i] = pll(x, y);
		K[i] = i;
	}
	
	cin >> S;
	
	for(i=1; i<=n; i++){
		if(P[K[i]] < P[K[1]]) swap(K[i], K[1]);
	}
	
	for(i=1; i<=n-2; i++){
		if(S[i - 1] == 'L'){
			for(j=i+1; j<=n; j++){
				if(ccw(P[K[i]], P[K[i + 1]], P[K[j]]) < 0){
					swap(K[j], K[i + 1]);
				}
			}
		}
		else{
			for(j=i+1; j<=n; j++){
				if(ccw(P[K[i]], P[K[i + 1]], P[K[j]]) > 0){
					swap(K[j], K[i + 1]);
				}
			}
		}
	}
	
	for(i=1; i<=n; i++){
		cout << K[i] << " ";
	}
	
	cout << endl;
	
	return 0;
}