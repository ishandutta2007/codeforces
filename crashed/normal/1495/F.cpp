    #include <set>
    #include <cmath>
    #include <cstdio>
    using namespace std;
     
    #define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
    #define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )
     
    typedef long long LL;
    typedef set<int> :: iterator Iter;
     
    const int MAXN = 2e5 + 5, MAXLOG = 20;
     
    template<typename _T>
    void read( _T &x )
    {
    	x = 0;char s = getchar();int f = 1;
    	while( s > '9' || s < '0' ){if( s == '-' ) f = -1; s = getchar();}
    	while( s >= '0' && s <= '9' ){x = ( x << 3 ) + ( x << 1 ) + ( s - '0' ), s = getchar();}
    	x *= f;
    }
     
    template<typename _T>
    void write( _T x )
    {
    	if( x < 0 ){ putchar( '-' ); x = ( ~ x ) + 1; }
    	if( 9 < x ){ write( x / 10 ); }
    	putchar( x % 10 + '0' );
    }
     
    struct Edge
    {
    	int to, nxt;
    }Graph[MAXN << 1];
     
    set<int> s;
     
    int buc[MAXN];
    bool vis[MAXN];
     
    int f[MAXN][MAXLOG];
    LL su[MAXN], bst[MAXN];
    int DFN[MAXN], dep[MAXN], seq[MAXN], head[MAXN];
    int stk[MAXN], top;
     
    int A[MAXN], B[MAXN], P[MAXN];
    int N, Q, cnt, lg2, ID; LL ans = 0;
     
    void AddEdge( const int from, const int to )
    {
    	Graph[++ cnt].to = to, Graph[cnt].nxt = head[from];
    	head[from] = cnt;
    }
     
    void DFS( const int u, const int fa )
    {
    	seq[DFN[u] = ++ ID] = u;
    	dep[u] = dep[fa] + 1, f[u][0] = fa;
    	for( int i = head[u], v ; i ; i = Graph[i].nxt )
    		if( ( v = Graph[i].to ) ^ fa )
    		{
    			DFS( v, u ), su[u] += B[v];
    			if( bst[v] < 0 ) bst[u] += bst[v], bst[v] = 0;
    		}
    	bst[u] += A[u] - B[u] + su[u];
    }
     
    void Init()
    {
    	DFS( 0, 0 ), lg2 = log2( N );
    	rep( j, 1, lg2 ) rep( i, 1, N ) 
    		f[i][j] = f[f[i][j - 1]][j - 1];
    	rep( i, 2, N ) bst[seq[i]] += bst[f[seq[i]][0]];
    }
     
    void Balance( int &u, const int stp )
    {
    	for( int i = 0 ; ( 1 << i ) <= stp ; i ++ )
    		if( stp >> i & 1 ) u = f[u][i];
    }
     
    int LCA( int u, int v )
    {
    	if( dep[u] > dep[v] ) Balance( u, dep[u] - dep[v] );
    	if( dep[v] > dep[u] ) Balance( v, dep[v] - dep[u] );
    	if( u == v ) return u;
    	per( i, lg2, 0 ) if( f[u][i] ^ f[v][i] ) u = f[u][i], v = f[v][i];
    	return f[u][0];
    }
     
    LL Dist( const int u, const int v ) { return bst[u] + bst[v] - 2 * bst[LCA( u, v )]; }
     
    void Insert( const int u )
    {
    	Iter it = ( s.insert( DFN[u] ), s.find( DFN[u] ) );
    	int pre = 0, nxt = 0;
    	if( it != s.begin() ) pre = seq[* -- it]; it ++;
    	if( it != s.end() && ( ++ it ) != s.end() ) nxt = seq[* it];
    	ans += Dist( u, pre ) + Dist( u, nxt ) - Dist( pre, nxt );
    }
     
    void Delete( const int u )
    {
    	set<int> :: iterator it = s.find( DFN[u] );
    	int pre = 0, nxt = 0; 
    	if( it != s.end() ) 
    	{
    		it ++;
    		if( it != s.end() )
    			nxt = seq[* it];
    		it --;
    	}
    	if( it != s.begin() ) pre = seq[* -- it];
    	ans -= Dist( u, pre ) + Dist( u, nxt ) - Dist( pre, nxt );
    	s.erase( DFN[u] );
    }
     
    int main()
    {
    	read( N ), read( Q );
    	rep( i, 1, N ) read( P[i] );
    	rep( i, 1, N ) read( A[i] );
    	rep( i, 1, N ) read( B[i] );
    	for( int i = 1 ; i <= N ; i ++ )
    	{
    		while( top && P[stk[top]] <= P[i] ) top --;
    		AddEdge( stk[top], i ), stk[++ top] = i;
    	}
    	Init();
    	for( int cur ; Q -- ; )
    	{
    		read( cur );
    		if( vis[cur] )
    		{
    			vis[cur] = false;
    			if( ! ( -- buc[f[cur][0]] ) )
    				Delete( f[cur][0] );
    		}
    		else
    		{
    			vis[cur] = true;
    			if( ! ( buc[f[cur][0]] ++ ) )
    				Insert( f[cur][0] );
    		}
    		write( ans / 2 + bst[0] ), putchar( '\n' );
    	}
    	return 0;
    }