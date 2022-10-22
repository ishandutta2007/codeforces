#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define FOR(i, j, n) for(int i = j; i <= n; ++i)
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl;
#define ios cin.tie(0); ios_base::sync_with_stdio(0)	
	
		
using namespace std;

int n;
int a[100001];	

vector <int> ind;

int main() {	
	scanf("%d", &n);
	a[0] = 1000000 + 1;
	FOR(i, 1, n)
		scanf("%d", a + i);
	bool inc = 1;
	bool dec = 1;
	FOR(i, 2, n) {
		inc &= a[i] >= a[i - 1];
		dec &= a[i] <= a[i - 1];
	}
	if(dec || inc) {
		printf("0\n");
		return 0;
	}
	printf("3 \n");
	inc = dec = 0;
	FOR(i, 2, n) {
		if(a[i] > a[i - 1]) {
			inc = 1;
			break;
		}
		if(a[i] < a[i - 1]) {
			dec = 1;
			break;
		}
	}
	
	FOR(i, 1, n) {
		if(a[i] != a[i - 1]) 
			ind.pb(i);
		if(inc) {
			if(ss(ind) > 2 && a[ind.back()] < a[ind[ss(ind) - 2]]) {
				FOR(i, ss(ind) - 3, ss(ind) - 1)
					printf("%d ", ind[i]);
				return 0;
			}
		}
		else {
			if(ss(ind) > 2 && a[ind.back()] > a[ind[ss(ind) - 2]]) {
				FOR(i, ss(ind) - 3, ss(ind) - 1)
					printf("%d ", ind[i]);
				return 0;
			}
		}
	}
	
	
	
			
	return 0;
}