#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <climits>
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <cassert>
#include <vector>
#define all(x) x.begin() , x.end()
#define fi first
#define se second
#define pb push_back
#define umax( x , y ) x = max( x , (y) )
#define umin( x , y ) x = min( x , (y) )
#define For( i , a ) for(int i=1;i<=a;i++)
#define ort (b+s)/2
#define y2 asrwjaelkf
#define y1 asseopirwjaelkf
 
using namespace std;
 
const int maxn = 200020;
const int maxm = 1000020;
const int logn = 18;
const int MOd = 1e9+7;
 
typedef long long Lint;
typedef long double db;
typedef pair<Lint,Lint> ii;
typedef pair<int,ii> iii;
 
int a, b, n;
int segment[2][maxn*3], ar[maxn], bs[maxn];
set <int> :: iterator it, it2;
set <int> sx, sy;
 
void up( int tp, int x, int y ) {
	x += n-1;
	segment[tp][x] = y;
	for( x >>= 1 ; x ; x >>= 1 )
		segment[tp][x] = max( segment[tp][2*x], segment[tp][2*x+1] );
}
 
int find( int tp, int l, int r ) {
	int t = 0;
	for( l += n-1, r += n-1; l<=r ; l = (l+1)>>1, r=(r-1)>>1 ) {
		if( l&1 ) umax( t, segment[tp][l] );
		if( ~r&1 ) umax( t, segment[tp][r] );
	}
	return t;
}
 
int main() {
	
	scanf("%d %d",&a,&b);
	
	n = 1;
	while( n < b+10 ) n <<= 1;
	
	for(int i=1,x,y,tp;i<=b;i++) {
		scanf("%d",&tp);
		//~ printf("asdasd\n");
		if( tp == 1 ) {
			scanf("%d %d",&x,&y);
			y = y-i+b;
			//~ printf("-- %d %d\n",x,y);
			ar[x] = y;
			bs[y] = x;
			sy.insert( y );
			sx.insert( x );
			for(it=sy.begin();(*it) != y;it++){
				up( 0, bs[*it], 0 );
				up( 1, *it, 0 );
			}
			for(;1;it--) {
				int t = find( 0, bs[*it]+1, n );
				up( 1, *it, t+1 );
				up( 0, bs[*it], t+1 );
				if( it == sy.begin() ) break;
			}
		} else {
			scanf("%d",&x);
			it = sx.begin();
			up( 0, *it, 0 );
			up( 1, ar[*it], 0 );
			for(int j=1;j<x;j++) {
				it++;
				up( 0, *it, 0 );
				up( 1, ar[*it], 0 );
			}
			//~ printf("--- %d %d\n",x,*it);
			it2 = it;
			if( it != sx.begin() ) {
				it--;
				for(;1;it--) {
					int t = find( 1, ar[*it]+1, n );
					up( 0, *it, t+1 );
					up( 1, ar[*it], t+1 );
					if( it == sx.begin() ) break;
				}
			}
			sy.erase( sy.lower_bound(ar[*it2]) );
			sx.erase( it2 );
		}
		printf("%d\n",segment[0][1]);
	}
	
	return 0;
}