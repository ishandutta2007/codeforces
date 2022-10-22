#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using pib = pair<int,bool>;
using ll = long long;
using ld = long double;
#define all(x) (x).begin(),(x).end()
#ifdef fread_unlocked
#define fread fread_unlocked
#define fwrite fwrite_unlocked
#endif
#define lc ind<<1
#define rc ind<<1|1
const int MN = 1e5+4, MOD = 1e9+7, BASE = 31;
bool prime (int n) {
	for (int i = 2; i * i <= n; i++) if (n%i==0) return 0;
	return n != 1;
}
int main () { 
	int n;
	scanf ("%d",&n);
	if (prime(n)) printf ("1\n%d\n",n);
	else if (prime(n-2)) printf ("2\n2 %d\n",n-2);
	else {
		n -= 3;
		printf ("3\n3 ");
		for (int i = 3; i <= n; i++) if (prime(n-i) && prime(i)) {
			printf("%d %d\n",i,n-i);
			break;
		}
	}
	return 0;
}