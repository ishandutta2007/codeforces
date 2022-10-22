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
int main () { 
	int c1,c2,c3,c4;
	scanf ("%d %d %d %d",&c1,&c2,&c3,&c4);
	if (c1 != c4) printf ("0\n");
	else if (c3 && c1<1) printf ("0\n");
	else printf ("1\n");
	return 0;
}