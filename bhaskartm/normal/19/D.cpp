#include <algorithm>
#include <cstdio>
#include <vector>
 
using namespace std;
 
const int oo = 1000000000;
 
struct point {
   int x, y;
   point( int x, int y ) : x(x), y(y) {}
};
inline bool operator < ( const point &A, const point &B ) {
   if( A.x != B.x ) return A.x < B.x;
   return A.y < B.y;
}
 
struct request {
   int type;
   point p;
   request( int type, const point &p ) : p(p), type(type) {}
};
 
int topmost[1<<19];
vector<point> P;
 
void add( int i, int lo, int hi, int x ) {
   if( x < lo || x >= hi ) return;
   if( lo+1 == hi ) {
      topmost[i] = P[x].y;
   } else {
      int mid = (lo+hi)/2;
      add( 2*i, lo, mid, x );
      add( 2*i+1, mid, hi, x );
 
      topmost[i] = max( topmost[2*i], topmost[2*i+1] );
   }
}
void remove( int i, int lo, int hi, int x ) {
   if( x < lo || x >= hi ) return;
   if( lo+1 == hi ) {
      topmost[i] = -oo;
   } else {
      int mid = (lo+hi)/2;
      remove( 2*i, lo, mid, x );
      remove( 2*i+1, mid, hi, x );
 
      topmost[i] = max( topmost[2*i], topmost[2*i+1] );
   }
}
 
point ret( -oo, -oo );
 
void find( int i, int lo, int hi, const point &p ) {
   if( p.x >= P[hi-1].x ) return;
   if( topmost[i] <= p.y ) return;
   
   if( lo+1 == hi ) {
      if( P[lo].x > p.x && P[lo].y > p.y ) ret = P[lo];
   } else {
      int mid = (lo+hi)/2;
      find( 2*i, lo, mid, p );
      if( ret.x == -oo ) 
         find( 2*i+1, mid, hi, p );
   }
}
 
int main( void ) {
   int n;
   vector<request> R;
 
   scanf( "%d", &n );
   for( int i = 0; i < n; ++i ) {
      static char command[32]; int x, y;
      scanf( "%s %d %d", command, &x, &y );
      R.push_back( request( command[0] == 'a' ? 1 : command[0] == 'r' ? 2 : 3, point(x, y) ) );
      if( command[0] != 'f' ) P.push_back( point(x, y) );
   }
 
   sort( P.begin(), P.end() ); 
   if( P.empty() ) P.push_back( point(0, 0) );
   
   for( int i = 0; i < (1<<19); ++i ) topmost[i] = -oo;
 
   int N = P.size();
   for( int i = 0; i < n; ++i ) {
      if( R[i].type == 1 ) {
         int x = lower_bound( P.begin(), P.end(), R[i].p ) - P.begin();
         add( 1, 0, N, x );
      }
      if( R[i].type == 2 ) {
         int x = lower_bound( P.begin(), P.end(), R[i].p ) - P.begin();
         remove( 1, 0, N, x );
      }
      if( R[i].type == 3 ) {
         ret = point( -oo, -oo );
         find( 1, 0, N, R[i].p );
         if( ret.x == -oo ) printf( "-1\n" );
         else printf( "%d %d\n", ret.x, ret.y );
      }
   }
   
   return 0;
}