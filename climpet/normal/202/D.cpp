#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <limits>
using namespace std;

int c[1000][1000];
int m, n;

typedef long long ll;

int main(){ 
    ll sx = 0, sy = 0, sc = 0;
    scanf("%d%d", &n, &m );
    for( int i = 0; i < n; ++i ){
        for( int j = 0; j < m; ++j ){
            scanf("%d", &c[i][j] );
            ll c_ = c[i][j];
            sx += (j+1) * c_;
            sy += (i+1) * c_;
            sc += c_;
        }
    }
    sc = sc ? sc : 1;

    int x_ = sx / sc;
    int y_ = sy / sc;
    int x0 = max( 0, x_ - 1);
    int y0 = max( 0, y_ - 1);
    int x1 = min( m, x_ + 1 );
    int y1 = min( n, y_ + 1 );

    int mx = 0;
    int my = 0;
    ll md = numeric_limits<ll>::max();

    for( int y = y0; y <= y1; ++y ){
        for( int x = x0; x <= x1; ++x ){
            ll s = 0;
            for( int i = 0; i < n; ++i ){
                for( int j = 0; j < m; ++j ){
                    ll dx = 4 * x - (4 * j + 2);
                    ll dy = 4 * y - (4 * i + 2);
                    s += c[i][j] * (dx * dx + dy * dy);
                }
            }
            if( md > s ){
                md = s;
                mx = x;
                my = y;
            }
        }
    }
    
    cout << md << '\n' << my << ' ' << mx << endl;
}