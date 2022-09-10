// {{{ by shik

#include <bits/stdc++.h>
#include <unistd.h>
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x),end(x)
#define REP(i,n) for ( int i=0; i<int(n); i++ )
#define REP1(i,a,b) for ( int i=(a); i<=int(b); i++ )
#define FOR(it,c) for ( auto it=(c).begin(); it!=(c).end(); it++ )
#define MP make_pair
#define PB push_back
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;

#ifdef SHIK
template<typename T>
void _dump( const char* s, T&& head ) { cerr<<s<<"="<<head<<endl; }

template<typename T, typename... Args>
void _dump( const char* s, T&& head, Args&&... tail ) {
    int c=0;
    while ( *s!=',' || c!=0 ) {
        if ( *s=='(' || *s=='[' || *s=='{' ) c++;
        if ( *s==')' || *s==']' || *s=='}' ) c--;
        cerr<<*s++;
    }
    cerr<<"="<<head<<", ";
    _dump(s+1,tail...);
}

#define dump(...) do { \
    fprintf(stderr, "%s:%d - ", __PRETTY_FUNCTION__, __LINE__); \
    _dump(#__VA_ARGS__, __VA_ARGS__); \
} while (0);

template<typename Iter>
ostream& _out( ostream &s, Iter b, Iter e ) {
    s<<"[";
    for ( auto it=b; it!=e; it++ ) s<<(it==b?"":" ")<<*it;
    s<<"]";
    return s;
}

template<typename A, typename B>
ostream& operator <<( ostream &s, const pair<A,B> &p ) { return s<<"("<<p.first<<","<<p.second<<")"; }
template<typename T>
ostream& operator <<( ostream &s, const vector<T> &c ) { return _out(s,ALL(c)); }
template<typename T>
ostream& operator <<( ostream &s, const set<T> &c ) { return _out(s,ALL(c)); }
template<typename A, typename B>
ostream& operator <<( ostream &s, const map<A,B> &c ) { return _out(s,ALL(c)); }
#else
#define dump(...)
#endif

void RI() {}

template<typename... T>
void RI( int& head, T&... tail ) {
    scanf("%d",&head);
    RI(tail...);
}
// }}}

const int N=2e5+10;

double mcs( int n, double a[N] ) {
    double mx=0,now=0;
    REP(i,n) {
        now+=a[i];
        if ( now>mx ) mx=now;
        if ( now<0 ) now=0;
    }
    return mx;
}

int n,a[N];
double b[N];

void calc( double m, double &vp, double &vn ) {
    REP(i,n) b[i]=a[i]-m;
    vp=mcs(n,b);
    REP(i,n) b[i]*=-1;
    vn=mcs(n,b);
    // dump(m,vp,vn);
}

int main() {
    RI(n);
    REP(i,n) RI(a[i]);
    double l=*min_element(a,a+n);
    double r=*max_element(a,a+n);
    REP(t,100) {
        double m=(l+r)/2,vp,vn;
        calc(m,vp,vn);
        if ( vp>vn ) l=m;
        else r=m;
    }
    double m=(l+r)/2,vp,vn;
    calc(m,vp,vn);
    printf("%.12f\n",max(vp,vn));
    return 0;
}