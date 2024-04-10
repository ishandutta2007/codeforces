#include<bits/stdc++.h>
#define ld long double
using namespace std;
int main(){
	int n;
	scanf("%d", &n);
	ld p[n];
	ld a[n];
	for(int i = 0; i < n; i++){
		int prob;
		scanf("%d", &prob);
		p[i] = 1.0 - prob/100.0;
		a[i] = p[i];
	}
	ld pN = 0.0;
	ld ans = 0;
	for(int i = n; i <= 300000; i++){
		ld k = 1.0, best = 0;
		for(int j = 0; j < n; j++){
				k *= (1.0 - a[j]);	
		}
 
		ans += (k - pN)*i;
		pN = k;
		
		int j_best = 0;
		for(int j = 0; j < n; j++){
			if((1.0 - a[j]*p[j])/(1.0 - a[j]) > best)
				j_best = j, best = (1.0 - a[j]*p[j])/(1.0 - a[j]);
		}
		a[j_best] *= p[j_best];
	}
 
	printf("%.8lf\n", (double)ans);
}