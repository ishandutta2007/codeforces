#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

char s[8];

long long rec( int be, long long a[] )
{
    if ( be == 1 )
        return a[1];
    int i, j, k, l;
    long long na[8];
    long long r = (1LL<<60);
    for ( i = 1; i <= be; i++ )
    {
        for ( j = i+1; j <= be; j++ )
        {
            if ( s[be] == '*' )
                na[1] = a[i]*a[j];
            else if ( s[be] == '+' )
                na[1] = a[i]+a[j];
            l = 1;
            for ( k = 1; k <= be; k++ )
            {
                if ( ( k != i ) && ( k != j ) )
                    na[++l] = a[k];
            }
            r = min( r, rec( be-1, na ) );
        }
    }
    return r;
}

int main()
{
    int i, j, k;
    long long a, b, c, d, f[8];
    char str[8];

    scanf( "%I64d %I64d %I64d %I64d", &a, &b, &c, &d );
    f[1] = a; f[2] = b; f[3] = c; f[4] = d;
    scanf( "%s", &str ); s[4] = str[0];
    scanf( "%s", &str ); s[3] = str[0];
    scanf( "%s", &str ); s[2] = str[0];
    cout << rec( 4, f ) << endl;
    return 0;
}