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
char s[MN]; int len[MN];
int main () { 
	scanf ("%s",s); 
	int n = strlen(s);
	printf ("%s",s);
	reverse(s,s+n);
	printf ("%s\n",s);
	return 0;
}