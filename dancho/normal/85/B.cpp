#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
using namespace std;

struct el
{
    long long ti;
    char ev;
    long long wh;
    bool operator<( const el& x ) const
    {
        return ti < x.ti;
    }
};

el make_el( long long ti, char ev, long long wh )
{
    el x; x.ti = ti; x.ev = ev; x.wh = wh;
    return x;
}

int n;
long long k1, k2, k3;
long long t1, t2, t3;
long long C[100020];

multiset<el> S;
int bf[4];
queue<el> q[4];

int main()
{
    int i, j, k;
    long long bsol = -1;

    scanf( "%I64d %I64d %I64d", &k1, &k2, &k3 );
    scanf( "%I64d %I64d %I64d", &t1, &t2, &t3 );

    scanf( "%d", &n );
    for ( i = 1; i <= n; i++ )
    {
        scanf( "%I64d", &C[i] );
        S.insert( make_el( C[i], 'I', i ) );
    }
    bf[1] = k1;
    bf[2] = k2;
    bf[3] = k3;

    multiset<el>::iterator it, jt;
    el a, b, c, d;
    while ( S.size() > 0 )
    {
        it = S.begin();
        a = (*it);
        S.erase( it );
//        cout << "EV " << a.ti << " " << a.ev << " " << a.wh << " " << q[1].size() << " " << q[2].size() << " " << q[3].size() << " " << bf[1] << " " << bf[2] << " " << bf[3] << endl;
        if ( a.ev == '1' )
        {
            bf[1]++;
            if ( ( bf[1] > 0 ) && ( q[1].size() > 0 ) )
            {
                b = q[1].front();
                q[1].pop();
                bf[1]--;
                S.insert( make_el( a.ti+t1, 'P', b.wh ) );
                S.insert( make_el( a.ti+t1, '1', b.wh ) );
            }
        }
        else if ( a.ev == '2' )
        {
            bf[2]++;
            if ( ( bf[2] > 0 ) && ( q[2].size() > 0 ) )
            {
                b = q[2].front();
                q[2].pop();
                bf[2]--;
/*                bf[1]++;
                if ( ( bf[1] > 0 ) && ( q[1].size() > 0 ) )
                {
                    c = q[1].front();
                    q[1].pop();
                    bf[1]--;
                    S.insert( make_el( a.ti+t1, 'P', c.wh ) );
                }*/
                S.insert( make_el( a.ti+t2, 'S', b.wh ) );
                S.insert( make_el( a.ti+t2, '2', b.wh ) );
            }
        }
        else if ( a.ev == '3' )
        {
            bf[3]++;
            if ( ( bf[3] > 0 ) && ( q[3].size() > 0 ) )
            {
                b = q[3].front();
                q[3].pop();
                bf[3]--;
/*                bf[2]++;
                if ( ( bf[2] > 0 ) && ( q[2].size() > 0 ) )
                {
                    d = q[2].front();
                    q[2].pop();
                    bf[2]--;
                    bf[1]++;
                    if ( ( bf[1] > 0 ) && ( q[1].size() > 0 ) )
                    {
                        c = q[1].front();
                        q[1].pop();
                        bf[1]--;
                        S.insert( make_el( a.ti+t1, 'P', c.wh ) );
                    }
                    S.insert( make_el( a.ti+t2, 'S', d.wh ) );
                }*/
                S.insert( make_el( a.ti+t3, '3', b.wh ) );
                bsol = max( bsol, a.ti+t3-C[b.wh] );
            }
        }
        else if ( a.ev == 'I' )
        {
            q[1].push( a );
            if ( bf[1] > 0 )
            {
                b = q[1].front();
                q[1].pop();
                bf[1]--;
                S.insert( make_el( a.ti+t1, 'P', b.wh ) );
                S.insert( make_el( a.ti+t1, '1', b.wh ) );
            }
        }
        else if ( a.ev == 'P' )
        {
            q[2].push( a );
            if ( bf[2] > 0 )
            {
                b = q[2].front();
                q[2].pop();
                bf[2]--;
/*                bf[1]++;
                if ( ( bf[1] > 0 ) && ( q[1].size() > 0 ) )
                {
                    c = q[1].front();
                    q[1].pop();
                    bf[1]--;
                    S.insert( make_el( a.ti+t1, 'P', c.wh ) );
                }*/
                S.insert( make_el( a.ti+t2, 'S', b.wh ) );
                S.insert( make_el( a.ti+t2, '2', b.wh ) );
            }
        }
        else if ( a.ev == 'S' )
        {
            q[3].push( a );
            if ( bf[3] > 0 )
            {
                b = q[3].front();
                q[3].pop();
                bf[3]--;
/*                bf[2]++;
                if ( ( bf[2] > 0 ) && ( q[2].size() > 0 ) )
                {
                    d = q[2].front();
                    q[2].pop();
                    bf[2]--;
                    bf[1]++;
                    if ( ( bf[1] > 0 ) && ( q[1].size() > 0 ) )
                    {
                        c = q[1].front();
                        q[1].pop();
                        bf[1]--;
                        S.insert( make_el( a.ti+t1, 'P', c.wh ) );
                    }
                    S.insert( make_el( a.ti+t2, 'S', d.wh ) );
                }*/
                S.insert( make_el( a.ti+t3, '3', b.wh ) );
                bsol = max( bsol, a.ti+t3-C[b.wh] );
            }
        }
//        cout << "EV " << a.ti << " " << a.ev << " " << a.wh << " " << q[1].size() << " " << q[2].size() << " " << q[3].size() << " " << bf[1] << " " << bf[2] << " " << bf[3] << " " << S.size() << endl;
    }
    cout << bsol << endl;
    return 0;
}