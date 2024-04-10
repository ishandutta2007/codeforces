#include <cstdio>
#include <cstring>

const int mod = 12345;

long long n;
int c;
int m[32];

int tt[1024], mm[1024];

int getSt( int ma, int p )
{
        int st = 1;
        for ( int i = 0; i < p; i++ )
        {
            if ( m[i] == -1 ) continue;
                st = st * m[i];
        }
        int x = (ma/st)%m[p];
        return x;
}

int next( int ma, int p )
{
        if ( m[p] == 1 ) return ma;
        int st = 1;
        for ( int i = 0; i < p; i++ )
        {
            if ( m[i] == -1 ) continue;
                st = st * m[i];
        }
        int x = (ma/st)%m[p];
        if ( x == m[p]-1 ) return ma - (m[p]-1)*st;
        return ma + st;
}

int col[128];
int bma[128][128];

int re[128][128];

void mmatr( int sz, int a[128][128], int b[128][128], int c[128][128] )
{
        int i, j, k;
        for ( i = 0; i < sz; i++ )
        {
                for ( j = 0; j < sz; j++ )
                {
                        c[i][j] = 0;
                        for ( k = 0; k < sz; k++ )
                        {
                                c[i][j] = c[i][j] + a[i][k]*b[k][j];
                                if ( c[i][j] >= mod ) c[i][j] = c[i][j] % mod;
                        }
                }
        }
}

void mcpy( int sz, int a[128][128], int b[128][128] )
{
        int i, j;
        for ( i = 0; i < sz; i++ )
        {
                for ( j = 0; j < sz; j++ )
                {
                        a[i][j] = b[i][j];
                }
        }
}

void mpow( int sz, int ma[128][128], long long st )
{
        int a[128][128], b[128][128];
        int i, j;
        for ( i = 0; i < sz; i++ )
        {
                for ( j = 0; j < sz; j++ )
                        re[i][j] = 0;
                re[i][i] = 1;
        }

        while ( st > 0 )
        {
                if ( st % 2 == 1 )
                {
                        mmatr( sz, re, ma, a );
                        mcpy( sz, re, a );
                }
                st = st / 2;
                mcpy( sz, b, ma );
                mmatr( sz, ma, b, a );
                mcpy( sz, ma, a );
        }
}

int main()
{
        int i, j, k, t;
        int mp = 1;
        char x[8];

        memset( m, -1, sizeof( m ) );

        scanf( "%I64d %d", &n, &c );
        for ( i = 1; i <= c; i++ )
        {
                scanf( "%s %d", x, &k );
                t = x[0]-'A';
                if ( m[t] == -1 ) m[t] = 1;
                m[t] = m[t] * k;

                tt[i] = t; mm[i] = k;
                mp = mp * k;
        }

        memset( col, 0, sizeof( col ) );
        col[0] = 1;

        memset( bma, 0, sizeof( bma ) );

        for ( i = 0; i < mp; i++ )
        {
                for ( j = 0; j <= 26; j++ )
                {
                        if ( m[j] == -1 ) continue;
                        bma[i][next( i, j )]++;
                }
        }

/*      for ( i = 0; i < 20; i++ )
        {
                printf( "%d ", m[i] );
        }
        printf( "\n" );

        printf( "%d\n", mp );
        for ( i = 0; i < mp; i++ )
        {
                for ( j = 0; j < mp; j++ )
                        printf( "%d ", bma[i][j] );
                printf( "\n" );
        }*/

        mpow( mp, bma, n );

        int res = 0;
        for ( j = 0; j < mp; j++ )
        {
                for ( k = 0; k <= 26; k++ )
                {
                        if ( m[k] == -1 ) continue;
                        if ( m[k] == 1 ) continue;
                        int st = getSt( j, k );
                        //printf( "ST %d %d %d\n", j, k, st );
                        for ( i = 1; i <= c; i++ )
                        {
                                if ( tt[i] == k )
                                        if ( st % mm[i] == 0 )
                                                break;
                        }
                        if ( i > c ) break;
                }
                if ( k <= 26 ) continue;
                res = res + re[0][j];
                if ( res >= mod ) res = res % mod;
                //printf( "OK %d %d\n", j, re[j][j] );
/*              for ( i = 0; i < mp; i++ )
                {
                        res = res + re[j][i];
                        if ( res >= mod ) res = res % mod;
                }*/
        }

/*        for ( i = 0; i < mp; i++ )
        {
                for ( j = 0; j < mp; j++ )
                        printf( "%d ", re[i][j] );
                printf( "\n" );
        }*/
        printf( "%d\n", res );
        return 0;
}