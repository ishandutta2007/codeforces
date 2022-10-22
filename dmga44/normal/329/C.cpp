#include<bits/stdc++.h>
#pragma GCC optimize(/*"Ofast"*/,"unroll-loops","omit-frame-pointer","inline")
#pragma GCC optimization("O3")
using namespace std;

///Macros
#define int  long long
#define it(x) x::iterator
#define pb push_back
#define pf push_front
#define lb lower_bound
#define up upper_bound
#define fs first
#define sc second
#define endl '\n'
#define pf push_front
#define all(x) x.begin() , x.end()
#define mp make_pair

#define FOR(i,a,n) for(int i=a;i<(n);i++)
#define FO(i,n) for(int i=0;i<(n);i++)
#define RFOR(i,a,n) for(int i=(n)-1;i>=a;i--)
#define RFO(i,n) for(int i=(n)-1;i>=0;i--)
#define gof(i,n) for(auto &i: n);

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector< ii > vii;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

///Constraints:
const int inf = ((1ll<<31ll)-1ll);
const int INF = (((1ll<<59ll)-1ll)*2ll)+1ll;
const ull mod = 998244353;
const ld pi = acos(-1);
/// Functions:
#define lg2(x) 31 - __builtin_clz(x)
#define lg2ll(x) 63 - __builtin_clzll(x)
#define lgx(x,b) ( log(x) / log(b) )
#define YN(x) cout<<((x)?("YES"):("NO"))<<fl;
#define yn(x) cout<<((x)?("Yes"):("No"))<<fl;
/*void print(vector<int>v){for(auto that:v)cout<<that<<" ";cout<<endl;}
vector<int>read(int cnt){vi v(cnt);for(int i=0;i<cnt;i++)cin>>v[i];return v;}*/


/*#include<ext/pb_ds/assoc_container.hpp> // Common file
#include<ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace __gnu_pbds;
//comenta el define long long int
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;*/
// find_by_order
// order_of_key



/// Quick Pow------------------------------------------------
int qpow(int b,int e)
{
    if( !e ) return 1;
    if( e & 1 ) return qpow(b,e-1) * b %mod ;
    int pwur = qpow(b,e>>1);
    return pwur * pwur %mod;
}
///Inverso Modular
int InverM(int a,int b)
{
    int eso=a-(a/b)*b;
    if(eso==0)
        return 0;
    int ans=(1-b*InverM(b,eso))/eso;
    if(ans<0)
        ans+=b;
    return ans;

}



/// Variables------------------------------------------------
int tc,n,m,k,q;
vector<vector<int> > A;
vector<int> G[100002];
int mark[100002];
void DFS(int u,int p)
{
    mark[u]=1;
    A.back().pb(u);
    for(int i=0; i<G[u].size(); i++)
    {
        int v=G[u][i];
        if(v==p)
            continue;
        if(mark[v])
            break;
        DFS(v,u);
    }

}
bool fun(vector<int> A,vector<int> B)
{
    return A.size()>B.size();
}
void problem()
{
    cin>>n>>m;
    bool b= m==n;
    for(int i=0; i<m; i++)
    {
        int a,b;
        cin>>a>>b;
        G[a].pb(b);
        G[b].pb(a);
    }
    for(int i=1; i<=n; i++)
    {
        if(!mark[i])
        {
            A.pb(vector<int>());
            DFS(i,-1);
        }
    }

    if(n==2 && m==1)
    {
        cout<<-1;
        return;
    }
    if(n==3 && m>=2)
    {
        cout<<-1;
        return;
    }
    if(n==4 && m>=4)
    {
        cout<<-1;
        return;
    }

    sort(all(A),fun);
    if(n==4 && m==3){
        if(A.size()>1){
            cout<<-1;
            return;
        }
        swap(A[0][0],A[0][1]);
        swap(A[0][1],A[0][2]);
        swap(A[0][1],A[0][3]);
        for(int i=0;i<3;i++){
            cout<<A[0][i]<<' '<<A[0][i+1]<<endl;
        }
        return;

    }


    if(A.back().size()==1 && A[0].size()==4)
    {
        int  f=A.back()[0];
        A[0].pb(f);
        A.erase(A.end()-1);
    }

    for(int i=0; i<A.size(); i++)
    {
        int c=A[i].size();
        if(c<=2)
            continue;
        if(c==3)
        {
            swap(A[i][1],A[i][2]);
            continue;
        }
        if(c==4 && b)
        {
            swap(A[i][2],A[i][3]);
            continue;
        }
        vector<int> cur;
        for(int j=0; j<c; j+=2)
        {
            cur.pb(A[i][j]);
        }
        for(int j=1; j<c; j+=2)
        {
            cur.pb(A[i][j]);
        }

        if(c%2==0)
        {
            swap(cur[c-1],cur[c-2]);
        }
        A[i]=cur;
    }

    int fir=A[0].back();
    int n=A.size();
    int last=A[0].back();
    A[0].erase(A[0].end()-1);
    int ite=(bool)(A.size()-1);
    while(n)
    {
        if(A[ite].size()==0)
        {
            n=ite;
            ite=0;
            continue;
        }

        cout<<last<<' '<<A[ite].back()<<endl;
        last=A[ite].back();
        A[ite].erase(A[ite].end()-1);
        m--;
        if(!m)
            break;
        if(ite+1==n)
        {
            ite=0;
        }
        else
        {
            ite++;
        }
    }
    if(b)
    {
        cout<<last<<' '<<fir;
    }


}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.setf(ios::fixed);
    cout.precision(12);
    //freopen("a.in","w",stdin)
    //freopen("a.out","w",stdout);

    tc=1;
    while(tc--)
    {

        problem();
    }
    return 0;
}





///Tips
//Busqueda Binaria
//Precomputing
//Dinamic Programming
//Revisar constraints