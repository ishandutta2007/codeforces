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

const int nax = 2e5 + 111;
const int mod = 1e9 + 7;

int n;
int a[nax], b[nax];
vector <int> Plus, Minus;
int sum = 0;
					
int main() {	
	scanf("%d", &n);
	FOR(i, 1, n) {
		scanf("%d", a + i);
		if(abs(a[i]) % 2 == 1) {
			if(a[i] > 0)
				Plus.pb(i);
			else
				Minus.pb(i);
		}
		a[i] /= 2;
		sum += a[i];
	}
	int wsk = 0;
	while(sum > 0) {
		sum -= 1;
		a[Minus[wsk++]] -= 1;
	}
	wsk = 0;
	while(sum < 0) {
		sum += 1;
		a[Plus[wsk++]] += 1;
	}
	
	FOR(i, 1, n)
		printf("%d ", a[i]);
	
		
		
	
	
				
	return 0;
}