#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const int MN = 3e5+2, MOD = 1e9+7;
#define all(x) (x).begin(),(x).end()
int main() {
    int t;
	scanf ("%d",&t);
	while (t--) {
		int n,n1,n2,m1=0,m2=0;
		scanf ("%d %d %d",&n,&n1,&n2);
		for (int i = 1; i <= n1; i++) {
			int a;
			scanf ("%d",&a);
			m1 = max(m1,a);
		}
		for (int i = 1; i <= n2; i++) {
			int a;
			scanf ("%d",&a);
			m2 = max(m2,a);
		}
		printf(m1 > m2 ? "YES\n" : "NO\n");
	}
    return 0;
}