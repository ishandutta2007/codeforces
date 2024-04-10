#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const int MN = 202, MOD = 1e9+7, B = 300;
#define all(x) (x).begin(),(x).end()
int main() {
    int n,m;
	scanf ("%d %d",&n,&m);
	if (m%n != 0) return !printf ("-1\n");
	m /= n; int ret = 0;
	while (m%2==0) ret++, m/=2;
	while (m%3==0) ret++, m/=3;
	if (m != 1) return !printf ("-1\n");
	printf ("%d\n",ret);
    return 0;
}