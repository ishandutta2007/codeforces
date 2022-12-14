#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
char s[200020];

char c[200020];

vector<int> pos[28];
bool us[28];

int ia( int x )
{
    if ( x < 0 ) return -x;
    return x;
}

int main()
{
    int i, j, l, r;
    long long f;
    vector<int>::iterator it;
    scanf( "%d %d", &n, &k );
    scanf( "%s", s );
    for ( j = 0; j < 26; j++ ) pos[j].clear();
    for ( j = 0; j < k; j++ )
    {
        pos[s[j]-'a'].push_back( j );
    }
    for ( i = 1; i <= n; i++ )
    {
        scanf( "%s", c );
        l = strlen( c );
        f = 0;
        memset( us, 0, sizeof( us ) );
        for ( j = 0; j < l; j++ )
        {
            if ( pos[c[j]-'a'].size() == 0 )
            {
                f = f + l;
                continue;
            }
            us[c[j]-'a'] = 1;
            it = lower_bound( pos[c[j]-'a'].begin(), pos[c[j]-'a'].end(), j );
            r = (1<<29);
            if ( it != pos[c[j]-'a'].end() )
                r = (*it);
            if ( it != pos[c[j]-'a'].begin() )
                it--;
            if ( ia( (*it) - j ) < ia( r-j ) )
                r = (*it);
            f = f + ia(r-j);
        }
        printf( "%I64d\n", f );
    }
    return 0;
}