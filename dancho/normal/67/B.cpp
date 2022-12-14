#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int n, k;
int all;
int sm[1024];
int b[1024], a[1024];
bool us[1024];

int sum( int p )
{
    p = min( p, n );
    int i, r = 0;
    for ( i = p; i > 0; i = (i&(i-1)) )
        r = r + sm[i];
    return all - r;
}

void add( int p, int x )
{
    p = min( p, n );
    int i;
    for ( i = p; i <= n; i = i + (i&(-i)) )
        sm[i] = sm[i] + x;
}

int main()
{
    int i, j, l;
    all = 0;

    memset( sm, 0, sizeof( sm ) );
    memset( us, 0, sizeof( us ) );
    scanf( "%d %d", &n, &k );
    for ( i = 1; i <= n; i++ )
    {
        scanf( "%d", &b[i] );
    }
    for ( i = 1; i <= n; i++ )
    {
        for ( j = 1; j <= n; j++ )
        {
            if ( us[j] ) continue;
//            cout << "P " << i << " " << j << " " << sum( j+k-1 ) << " " << b[j] << endl;
            if ( b[j] == 0 )
//            if ( sum( j + k -1 ) == b[j] )
            {
                a[i] = j;
                for ( l = 1; l <= j-k; l++ )
                {
                    if ( b[l] > 0 ) b[l]--;
                }
//                add( j, 1 );
//                cout << "ADD " << j << endl;
//                all++;
                us[j] = 1;
                break;
            }
        }
        if ( i < n ) printf( "%d ", a[i] );
        else printf( "%d\n", a[i] );
    }
    return 0;
}