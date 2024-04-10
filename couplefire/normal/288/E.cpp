
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
#include<map>
#include<string>
#include<vector>
#define M 100007
#define N 1000010
using namespace std;
#define eps 1e-8
#define ll long long
#define mod 1000000007
const long long inf = 1LL<<62;
 
char l[M], r[M];
ll two[M], ten[M], a[M], b[M], c[M], tmp, res;
 
 void MOD( ll &a )
 {
     a %= mod;
     if( a < 0 ) a += mod;
 }
 
 ll solve( char *s )
 {
     int n = strlen( s );
     ll ans = 0, tmp = 0, res = 0;
     for( int i = 0; i < n; ++i ){
        res = (10*res + s[i] - '0') % mod;
        int j = n - i - 1;
        if( s[i] == '7' ){
            if( i == n-1 ){
                ans += res*(res-3)%mod; MOD( ans );
            }
            else{
                ans += tmp*tmp%mod*two[j]%mod; MOD( ans );
                ans += tmp*(b[j-1]) % mod; MOD( ans );
                ans += a[j-1]; MOD( ans );
                tmp += 3*ten[j]; MOD( tmp );
            }
        }
     }
     return ans;
 }
int main()
{
    int n;
    //cout<<1LL*(mod+30)*(mod+30)<<endl;
    scanf( "%s%s", l, r );
    n = strlen( l );
    tmp = 4;
    two[0] = ten[0] = 1;
    for( int i = 1; i < n; ++i ){
        two[i] = ( two[i-1]<<1 ) % mod;
        ten[i] = ( ten[i-1]*10 ) % mod;
        tmp = ( tmp*10 + 4 ) % mod;
    }
    res = tmp;
    a[0] = ( tmp * (tmp+3) ) % mod;
    a[0] = ( (tmp+3)*(tmp+30)%mod + a[0] ) % mod;
    b[0] = ( tmp + tmp+3 + tmp+3 + tmp+30 ) % mod;
    tmp += 3; MOD( tmp );
    for( int i = 1; i < n; ++i ){
        a[i] = ( ten[i]*ten[i] % mod * 3 * 3 % mod * (two[i]-1) ) % mod;
        MOD( a[i] );
        a[i] += (3*ten[i]%mod * ((b[i-1]-res-tmp-3*ten[i])%mod)) % mod; MOD( a[i] );
        a[i] += (a[i-1] - tmp*((res+3*ten[i]))%mod)%mod; MOD( a[i] );
        b[i] += b[i-1]; MOD( b[i] );
        b[i] += (b[i-1] + (two[i]*6%mod*ten[i])%mod) % mod; MOD( b[i] );
        b[i] += 3*ten[i+1] - 6*ten[i]; MOD( b[i] );
        tmp += 3*ten[i]; MOD( tmp );
        a[i] += a[i-1]; MOD( a[i] );
        a[i] += tmp*((res+3*ten[i+1])%mod)%mod; MOD( a[i] );
    }
    ll ans = solve( r ) - solve( l ); MOD( ans );
    cout<<ans<<endl;
}