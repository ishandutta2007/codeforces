#include <bits/stdc++.h>
#define ll long long
#define null NULL

using namespace std;


class hull_optimizer {
    /**
     * Line y=a*x+b represented by 2 coefficients a and b
     * and xLeft which is intersection with previous/next line in hull(first line has -INF)
     */
public:
    enum Type {line, maxQuery, minQuery};

    struct Line {
        long long a, b;
        double xLeft;
        long long val;
        Type type;

        explicit Line( long long aa = 0, long long bb = 0 ) : a( aa ), b( bb ), xLeft( -1e16 ), type( line ), val( 0 ) {}
        long long valueAt( long long x ) const { return a * x + b; }
        friend bool areParallel( const Line& l1, const Line& l2 ) { return l1.a == l2.a; }
        friend double intersectX( const Line& l1, const Line& l2 ) { return areParallel( l1, l2 ) ? 1e16 : 1.0 * ( l2.b - l1.b ) / ( l1.a - l2.a ); }
        bool operator<( const Line& l2 ) const {
            if ( l2.type == line )
                return this->a < l2.a;
            if ( l2.type == maxQuery )
                return this->xLeft < l2.val;
            if ( l2.type == minQuery )
                return this->xLeft > l2.val;
        }

        void show() const {
            cout << " [M = " << a << ", C = " << b << ", Type = " << type << ", xLeft = " << xLeft << "] ";
        }
    };

    bool isMax; //whether or not saved envelope is Upper/Max(search of max value) or Lower/Min(search of lower)
    std::set<Line> hull;  //envelope/Hull itself

    std::set<Line>::iterator next( std::set<Line>::iterator it ) { return ++it; }
    std::set<Line>::iterator prev( std::set<Line>::iterator it ) { return --it; }
    bool hasPrev( std::set<Line>::iterator it ) { return it != hull.begin(); }
    bool hasNext( std::set<Line>::iterator it ) { return it != hull.end() && next( it ) != hull.end(); }

    bool irrelevant( const Line& l1, const Line& l2, const Line& l3 ) { return intersectX( l1, l3 ) <= intersectX( l1, l2 ); }
    bool irrelevant( std::set<Line>::iterator it ) {
        return ( ( hasPrev( it ) && hasNext( it ) )
                 && ( ( isMax && irrelevant( *prev( it ), *it, *next( it ) ) )
                      || ( !isMax && irrelevant( *next( it ), *it, *prev( it ) ) ) ) );
    }

    /**
     *Updates intersectionX of line pointed by iterator 'it'
     */
    std::set<Line>::iterator updateLeftBorder( std::set<Line>::iterator it ) {
        if ( ( isMax && !hasPrev( it ) ) || ( !isMax && !hasNext( it ) ) )
            return it;

        double val = intersectX( *it, isMax ? *prev( it ) : *next( it ) );
        Line ModifiedLine( *it );
        __typeof( hull.begin() ) temp_it = it;
        it++;
        hull.erase( temp_it );
        ModifiedLine.xLeft = val;
        it = hull.insert( it, ModifiedLine );
        return it;
    }

    hull_optimizer( bool isMax ): isMax( isMax ) {}
    hull_optimizer(): isMax( false ) {} /**set false for by-default MinHull/LowerHull/LowerEnvelope/BestMin and true for UpperHull */

    /**
     * Adding line to the envelope/Hull
     * Line is of type y=a*x+b represented by 2 coefficients a and b
     */
    void addLine( long long a, long long b ) {
        //find the place where line will be inserted in set
        Line l3 = Line( a, b );
        __typeof( hull.begin() ) it = hull.lower_bound( l3 );
        //if parallel line is already in set, one of them becomes irrelevant
        if ( it != hull.end() && areParallel( *it, l3 ) ) {
            if ( ( isMax && it->b < b ) || ( !isMax && it->b > b ) ) {
                __typeof( hull.begin() ) temp_it = it;
                it++;
                hull.erase( temp_it );
            }
            else return;
        }
        //try to insert
        it = hull.insert( it, l3 );
        if ( irrelevant( it ) ) { hull.erase( it ); return; }
        //remove lines which became irrelevant after inserting line
        while ( hasPrev( it ) && irrelevant( prev( it ) ) ) hull.erase( prev( it ) );
        while ( hasNext( it ) && irrelevant( next( it ) ) ) hull.erase( next( it ) );
        //update the intersectionX of current line with next/prev line
        it = updateLeftBorder( it );
        if ( hasPrev( it ) )
            updateLeftBorder( prev( it ) );
        if ( hasNext( it ) )
            updateLeftBorder( next( it ) );
    }

    long long getBest( long long x ) const {
        Line q;
        q.val = x;
        q.type = isMax ? maxQuery : minQuery;
        __typeof( hull.begin() ) bestLine = hull.lower_bound( q );
        if ( isMax ) --bestLine;
        if( bestLine == hull.end() ) {
            return 1e16;
        }
        return bestLine->valueAt( x );
    }

    void show() const {
        puts( "Now Hull:" );
        for( __typeof( hull.begin() ) it = hull.begin(); it != hull.end(); it++ ) {
            it->show();
        }
        puts( "\n" );
    }
};

const ll INF = 1e18;
const int mx = 3e5;
int n;
ll a[mx], b[mx], dp[mx];
vector<int> g[mx];

hull_optimizer* dfs(int v, int pv) {
	int pos = -1;
	vector<hull_optimizer*> children;
	for (auto v1 : g[v]) {
		if (v1 != pv) {
			hull_optimizer *cur = dfs(v1, v);
			if (pos == -1 || cur->hull.size() > children[pos]->hull.size())
				pos = children.size();
			children.push_back(cur);
			dp[v] = min(dp[v], cur->getBest(a[v]));
		}
	}
	if (pos == -1) {
		dp[v] = 0;
		hull_optimizer *res = new hull_optimizer();
		res->addLine(b[v], dp[v]);
		return res;
	}
	for (int i = 0; i < children.size(); ++i) {
		if (i != pos) {
			for (auto cur_line : children[i]->hull) {
				children[pos]->addLine(cur_line.a, cur_line.b);
			}
		}
	}
	children[pos]->addLine(b[v], dp[v]);
	return children[pos];
}

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
	}
	for (int i = 0; i < n; ++i) {
		dp[i] = INF;
	}
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(0, 0);
	for (int i = 0; i < n; ++i) {
		cout << dp[i] << " ";
	}
	cout << endl;
}