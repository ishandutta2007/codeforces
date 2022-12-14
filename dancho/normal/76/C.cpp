#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int n, k, t;
char str[200020];
int g[200020];
int r[32], a[32][32];
bool hv[32];

int sm[1<<22];
bool inq[1<<22];

int main()
{
    int i, j, l, ma, pr, st;

    scanf( "%d %d %d", &n, &k, &t );
    scanf( "%s", str );
    for ( i = 0; i < k; i++ )
        scanf( "%d", &r[i] );
    for ( i = 0; i < k; i++ )
    {
        for ( j = 0; j < k; j++ )
            scanf( "%d", &a[i][j] );
    }

    memset( hv, 0, sizeof( hv ) );
    for ( i = 0; i < n; i++ )
    {
        g[i+1] = str[i]-'A';
        hv[g[i+1]] = 1;
    }

    memset( sm, 0, sizeof( sm ) );
    for ( j = 0; j < k; j++ )
    {
        ma = 0;
        pr = -1;
        for ( i = 1; i <= n; i++ )
        {
            if ( g[i] == j )
            {
                if ( pr != -1 )
                {
                    sm[ma] = sm[ma] + a[j][j];
                    sm[ma|(1<<j)] = sm[ma|(1<<j)] - a[j][j];
                }
                pr = i;
                ma = 0;
            }
            else
                ma = (ma|(1<<g[i]));
        }
    }

    for ( j = 0; j < k; j++ )
    {
        for ( l = j+1; l < k; l++ )
        {
//            if ( j == l ) continue;
            ma = 0;
            pr = -1;
            for ( i = 1; i <= n; i++ )
            {
                if ( g[i] == j )
                {
                    if ( pr == l )
                    {
                        sm[ma] = sm[ma] + a[l][j];
                        sm[ma|(1<<j)] -= a[l][j];
                        sm[ma|(1<<l)] -= a[l][j];
                        sm[ma|(1<<j)|(1<<l)] += a[l][j];
                    }
                    pr = g[i];
                    ma = 0;
                }
                else if ( g[i] == l )
                {
                    if ( pr == j )
                    {
                        sm[ma] = sm[ma] + a[j][l];
                        sm[ma|(1<<l)] -= a[j][l];
                        sm[ma|(1<<j)] -= a[j][l];
                        sm[ma|(1<<j)|(1<<l)] += a[j][l];
                    }
                    pr = g[i];
                    ma = 0;
                }
                else
                    ma = (ma|(1<<g[i]));
            }
        }
    }

    for ( j = 0; j < k; j++ )
    {
        sm[1<<j] += r[j];
    }

    int sol = 0;

    for ( j = 0; j < k; j++ )
    {
        for ( i = 0; i < (1<<k); i++ )
        {
            if ( i&(1<<j) )
            {
                sm[i] = sm[i] + sm[i^(1<<j)];
            }
        }
    }

    for ( i = 0; i < (1<<k)-1; i++ )
    {
        l = 0;
        for ( j = 0; j < k; j++ )
        {
            if ( ( i&(1<<j) ) && ( hv[j] == 0 ) )
                break;
            if ( ( (i&(1<<j))==0 ) && ( hv[j] == 1 ) )
                l++;
        }
//        cout << i << " " << j << " " << l << endl;
        if ( j < k || l == 0 ) continue;
        if ( sm[i] <= t )
        {
//            cout << "SOL " << i << endl;
            sol++;
        }
    }

    printf( "%d\n", sol );
    return 0;
}