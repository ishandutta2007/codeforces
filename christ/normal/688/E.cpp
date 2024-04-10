#include <string>
#include <bits/functexcept.h>
#include <iosfwd>
#include <bits/cxxabi_forced.h>
#include <bits/functional_hash.h>

#pragma push_macro("__SIZEOF_LONG__")
#pragma push_macro("__cplusplus")
#define __SIZEOF_LONG__ __SIZEOF_LONG_LONG__
#define unsigned unsigned long
#define __cplusplus 201102L

#define __builtin_popcountl __builtin_popcountll
#define __builtin_ctzl __builtin_ctzll

#include <bitset>

#pragma pop_macro("__cplusplus")
#pragma pop_macro("__SIZEOF_LONG__")
#undef unsigned
#undef __builtin_popcountl
#undef __builtin_ctzl

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
    bitset<505> dp[505];
    int main () { 
    	int n,k;
    	scanf ("%d %d",&n,&k); dp[0][0] = 1;
    	for (int i = 1; i <= n; i++) {
    		int c; scanf ("%d",&c);
    		for (int j = k; j >= c; j--) {
    		    dp[j] |= dp[j-c]<<c | dp[j-c];
    		}
    	}
    	printf ("%d\n",dp[k].count());
    	for (int j = 0; j <= k; j++) if (dp[k][j]) printf ("%d ",j);
    	printf ("\n");
    	return 0;
    }