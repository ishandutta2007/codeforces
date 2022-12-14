#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
using namespace std;

int n, q;
vector<int> g[1<<20], qu[1<<20], fi[1<<20], em[1<<20];

int ans[1<<20];

bool us[1<<20];

set<int> par, op[1<<20];

void dfs( int v ) {
  op[v].clear();
  for (int i = 0; i < (int) em[v].size(); ++i) {
    op[v].insert( em[v][i] );
  }

  for (int i = 0; i < (int) fi[v].size(); ++i) {
    par.insert( fi[v][i] );
  }

  for (int i = 0; i < (int) g[v].size(); ++i) {
    if ( !us[ g[v][i] ] ) {
      us[ g[v][i] ] =1;
      dfs( g[v][i] );
      if ( op[g[v][i]].size() > op[v].size() ) {
        swap( op[v], op[ g[v][i] ] );
      }
      for (set<int>::iterator it = op[g[v][i]].begin(); it != op[g[v][i]].end(); ++it) {
        op[v].insert( *it );
      }
      op[ g[v][i] ].clear();
    }
  }

  for (int i = 0; i < (int) qu[v].size(); ++i) {
    set<int>::iterator it;
    int f, e;
    f = -2;
    e = -1;

    it = par.lower_bound(qu[v][i]);
    if ( it != par.begin() ) {
      it--;
      f = (*it);
    }

    it = op[v].lower_bound(qu[v][i]);
    if ( it != op[v].begin() ) {
      it--;
      e = (*it);
    }

    if ( f > e )
      ans[qu[v][i]] = 1;
    else
      ans[qu[v][i]] = 0;
  }

  for (int i = 0; i < (int) fi[v].size(); ++i) {
    par.erase( fi[v][i] );
  }
}

int main() {
  int i, j, k;

  scanf( "%d", &n );
  for ( i = 1; i < n; i++ ) {
    scanf( "%d %d", &j, &k );
    g[j].push_back( k );
    g[k].push_back( j );
  }

  scanf( "%d", &q );
  for (int i = 0; i < q; ++i) {
    scanf( "%d %d", &j, &k );
    if ( j == 1 ) {
      fi[k].push_back( i );
    }
    else if ( j == 2 ) {
      em[k].push_back( i );
    }
    else if ( j == 3 ) {
      qu[k].push_back( i );
    }
  }

  memset( us, 0, sizeof( us ) );
  memset( ans, -1, sizeof( ans ) );
  us[1] = 1;
  dfs( 1 );

  for (int i = 0; i < q; ++i) {
    if (ans[i] != -1 )
      printf( "%d\n", ans[i]);
  }
  return 0;
}