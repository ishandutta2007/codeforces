    #include<bits/stdc++.h>
    #include<ext/pb_ds/assoc_container.hpp>
    #pragma GCC diagnostic ignored "-Wunused-result" 
    #pragma GCC diagnostic ignored "-Wsign-compare" 
    using namespace std;
    using namespace __gnu_pbds;
    using ll = long long;
    using pii = pair<int,int>;
    using pll = pair<ll,ll>;
    using ld = long double;
    #define all(x) (x).begin(),(x).end()
    #define io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifdef LOCAL
    #define setio(x)
    #else
    #define setio(x) freopen((x+".in").c_str(),"r",stdin); freopen((x+".out").c_str(),"w",stdout)
    #endif
    const int MN = 1e5+3, BASE = 31, LOG = 20;
    char s[MN*10];
    int main() {
        scanf ("%s",s);
    	int heavy = 0; ll ans = 0; int n = strlen(s);
    	for (int i = 0; i < n; i++) {
    	    if (s[i] == 'h' && s[i+1] == 'e' && s[i+2] == 'a' && s[i+3] == 'v' && s[i+4] == 'y') ++heavy;
    	    else if (s[i] == 'm' && s[i+1] == 'e' && s[i+2] == 't' && s[i+3] == 'a' && s[i+4] == 'l') ans += heavy;
    	}
    	printf ("%lld\n",ans);
    	return 0;
    }