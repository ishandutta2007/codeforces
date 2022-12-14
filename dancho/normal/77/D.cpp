#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;

string hor[16][16] = { { "...", "...", "..."},
                       { "...", ".O.", "..."},
                       { "O..", "...", "..O"},
                       { "O..", ".O.", "..O"},
                       { "O.O", "...", "O.O"},
                       { "O.O", ".O.", "O.O"},
                       { "OOO", "...", "OOO"}};

string ver[16][16] = { { "...", "...", "..."},
                       { "...", ".O.", "..."},
                       { "..O", "...", "O.."},
                       { "..O", ".O.", "O.."},
                       { "O.O", "...", "O.O"},
                       { "O.O", ".O.", "O.O"},
                       { "O.O", "O.O", "O.O"}};

const int mod = 1000000007;

int n, m;
char car[1024][1024];
int tp[256][256], td[256][256];
int dpv[256][256], dph[256], canv[256];

inline int type( int px, int py )
{
    int i, j, k;
    int ish, isv;
    ish = 0; isv = 0;
    for ( k = 0; k < 7; k++ )
    {
        for ( i = 0; i < 3; i++ )
        {
            for ( j = 0; j < 3; j++ )
            {
                if ( hor[k][i][j] != car[px+i][py+j] )
                    break;
            }
            if ( j < 3 ) break;
        }
        if ( i >= 3 )
            break;
    }
    if ( k < 7 ) ish = 1;

    for ( k = 0; k < 7; k++ )
    {
        for ( i = 0; i < 3; i++ )
        {
            for ( j = 0; j < 3; j++ )
            {
                if ( ver[k][i][j] != car[px+i][py+j] )
                    break;
            }
            if ( j < 3 ) break;
        }
        if ( i >= 3 )
            break;
    }
    if ( k < 7 ) isv = 1;

    if ( ( ish ) && ( isv ) ) return 3;
    if ( ish ) return 1;
    if ( isv ) return 2;
    return 0;
}

int getDPv( int x, int y )
{
    if ( x == n ) return 1;
    if ( x > n ) return 0;
    if ( dpv[x][y] != -1 )
        return dpv[x][y];
    int i, j, k;
    int res = 0;
    if ( (td[x][y]&1) )
        res = res + getDPv( x+1, y );
    if ( res >= mod ) res = res % mod;
    if ( (td[x][y]&2) && (td[x][y+1]&2) )
        res = res + getDPv( x+2, y );
    if ( res >= mod ) res = res % mod;
    dpv[x][y] = res;
//    cout << "GETDP V " << x << " " << y << " " << dpv[x][y] << endl;
    return dpv[x][y];
}

int getDPh( int x )
{
    if ( x == -1 )
        return 1;
    if ( x < -1 ) return 0;
    if ( dph[x] != -1 )
        return dph[x];
    long long res = 0;
    res = res + canv[x]*getDPh( x-1 );
    if ( res >= mod ) res = res % mod;
    if ( x > 0 )
    {
        long long k = getDPv( 0, x-1 );
        if ( ( canv[x] ) && ( canv[x-1] ) )
            k = k + mod-1;
        if ( x-1 < 0 ) k = 0;
        if ( k >= mod ) k = k - mod;
        res = res + k*getDPh( x-2 );
        if ( res >= mod ) res = res % mod;
    }
    dph[x] = res;
//    cout << "GETDP H " << x << " " << dph[x] << " " << k << endl;
    return dph[x];
}

int main()
{
    int i, j, k;

    scanf( "%d %d", &n, &m );
    for ( i = 0; i < 4*n+1; i++ )
    {
        scanf( "%s", car[i] );
    }
    for ( i = 0; i < n; i++ )
    {
        for ( j = 0; j < m; j++ )
        {
            tp[i][j] = type( 4*i+1, 4*j+1 );
//            cout << tp[i][j] << " ";
        }
//        cout << endl;
    }

    for ( i = 0; i < n-1; i++ )
    {
        for ( j = 0; j < m-1; j++ )
        {
            td[i][j] = 0;
            if ( (tp[i][j]&1) && (tp[i][j+1]&1) )
                td[i][j] = (td[i][j]|1);
            if ( (tp[i][j]&2) && (tp[i+1][j]&2) )
                td[i][j] = (td[i][j]|2);
//            cout << td[i][j] << " ";
        }
//        cout << endl;
    }
    i = n-1;
    for ( j = 0; j < m-1; j++ )
    {
        td[i][j] = 0;
            if ( (tp[i][j]&1) && (tp[i][j+1]&1) )
                td[i][j] = (td[i][j]|1);
//            cout << td[i][j] << " ";
    }
//    cout << endl;

    j = m-1;
    for ( i = 0; i < n-1; i++ )
    {
        td[i][j] = 0;
            if ( (tp[i][j]&2) && (tp[i+1][j]&2) )
                td[i][j] = (td[i][j]|2);
//            cout << td[i][j] << " ";
    }
//    cout << endl;
    td[n-1][m-1] = 0;

    memset( dpv, -1, sizeof( dpv ) );
    memset( dph, -1, sizeof( dph ) );

    for ( i = 0; i < m; i++ )
    {
        for ( j = 0; j < n; j++ )
        {
            if ( (tp[j][i]&2) == 0 )
                break;
        }
        if ( ( j < n ) || ( n%2 == 1 ) )
            canv[i] = 0;
        else
            canv[i] = 1;
//        cout << i << " " << canv[i] << endl;
    }
    printf( "%d\n", getDPh( m-1 ) );
    return 0;
}