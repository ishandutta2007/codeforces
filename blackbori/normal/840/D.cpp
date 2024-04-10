#include <bits/stdc++.h>

using namespace std;

mt19937 mrand(chrono::steady_clock::now().time_since_epoch().count());

const int rx = 1234567;
int R[2020202], ri;

vector <int> V[303030];
int A[303030], S[303030];
int n;

int main()
{
	srand(time(0));
	 
	vector <int> X;
	int q, i, l, r, d, k, x, v;
	
	for(i=0; i<rx; i++){
		R[i] = mrand();
	}
	
	scanf("%d%d", &n, &q);
	
	for(i=1; i<=n; i++){
		scanf("%d", A + i);
		V[A[i]].push_back(i);
	}
	
	for(; q--; ){
		scanf("%d%d%d", &l, &r, &k);
		d = r - l + 1;
		
		X.clear(); v = -1;
		
		for(i=0; i<200; i++){
			x = A[(R[++ri % rx] % d + d) % d + l];
			S[x] ++; X.push_back(x);
		}
		
		for(int &t: X){
			if(S[t] >= 12){
				x = upper_bound(V[t].begin(), V[t].end(), r) - 
					lower_bound(V[t].begin(), V[t].end(), l);
				if(x > (r - l + 1) / k){
					if(v == -1 || v > t) v = t;
				}
			}
			S[t] = 0;
		}
		
		printf("%d\n", v);
	}
	
	return 0;
}