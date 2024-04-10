#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
using pii = pair<int,int>;
const int MN = 4e5+5, MOD = 1e9+7, B = 300;
#define all(x) (x).begin(),(x).end()
void solve () {
	int L,v,l,r;
	scanf ("%d %d %d %d",&L,&v,&l,&r);
	printf ("%d\n",(l-1)/v+L/v-r/v);
}
int main() {
	int t;
	scanf ("%d",&t);
	while (t--) solve();
    return 0;
}