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
int n, m, k;
 
int main() {
	scanf("%d%d%d", &n, &m, &k);
	int row = 1;
	int col = 1;
	while(m * 2 < k) {
		row += 1;
		k -= m * 2;
	}
	while(3 <= k) {
		col += 1;
		k -= 2;
	}
	cout << row << " " << col << " ";
	if(k == 2)
		printf("R");
	else
		printf("L");
	
	
	return 0;
}