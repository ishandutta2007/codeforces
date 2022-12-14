#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef pair<int,int> pii;

int n, V;
int x[100020], t[100020];
pii a[100020];

int mp[100020];

int main()
{
    int i, j, k;
    int r1, r2;
    int l, r, m;

    scanf( "%d", &n );
    for ( i = 1; i <= n; i++ )
    {
        scanf( "%d %d", &x[i], &t[i] );
    }
    scanf( "%d", &V );

    for ( i = 1; i <= n; i++ )
    {
        a[i] = make_pair( x[i]+t[i]*V, t[i]*V-x[i] );
        mp[i] = -(1<<30);
    }
    sort( a + 1, a + n + 1 );

    mp[0] = mp[1];
    k = 0;
    for ( i = 1; i <= n; i++ )
    {
        if ( a[i].second >= mp[k] )
        {
            k++;
            mp[k] = a[i].second;
        }
        else
        {
            l = 0; r = k;
            while ( l + 1 < r )
            {
                m = (l+r)/2;
                if ( mp[m] > a[i].second )
                    r = m;
                else
                    l = m;
            }
            mp[r] = a[i].second;
        }
    }
    r2 = k;

    a[n+1] = make_pair( 0, 0 );
    sort( a + 1, a + n + 2 );

    j = -1;
    for ( i = 1; i <= n+1; i++ )
    {
        mp[i] = -(1<<30);
        if ( ( a[i] == make_pair( 0, 0 ) ) && ( j == -1 ) )
            j = i;
    }
    mp[1] = 0;
    k = 1;
//    cout << j << endl;
    for ( i = j+1; i <= n+1; i++ )
    {
//        cout << i << " " << a[i].second << endl;
        if ( a[i].second >= mp[k] )
        {
            k++;
            mp[k] = a[i].second;
        }
        else
        {
            l = 0; r = k;
            while ( l + 1 < r )
            {
                m = (l+r)/2;
                if ( mp[m] > a[i].second )
                    r = m;
                else
                    l = m;
            }
            if ( r > 1 )
                mp[r] = a[i].second;
        }
    }
//    for ( i = 1; i <= n+1; i++ )
//        cout << mp[i] << " ";
//    cout << endl;

    r1 = k-1;

    printf( "%d %d\n", r1, r2 );
    return 0;
}