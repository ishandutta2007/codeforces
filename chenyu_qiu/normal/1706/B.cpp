#include <bits/stdc++.h>
using namespace std;
#define f(n) for (int i = 0; i < n; i++)
#define loop(i, a, b) for (int i = a; i < b; i++)
#define loopr(i, a, b) for (int i = a; i >= b; i--)
#define E '\n'
#define pb emplace_back
#define F first
#define S second
#define vi vector<int>
#define SUM(a) accumulate(a.begin(), a.end(), 0)
#define sort(x) sort(x.begin(), x.end())
#define int long long
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
 
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
 
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.F); cerr << ","; _print(p.S); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
 
template <typename T>
istream &operator>>(istream &istream, vector<T> &v)
{
    for (auto &it : v)
        cin >> it;
    return istream;
}
//======================================******ANKUSH************===========================================
void solve()
{
    int n;
    cin>>n;
    vi a(n),m(n+1,-1),ans(n+1,0);
    cin>>a;
    
    f(n){
        if(m[a[i]]==-1){
            m[a[i]]=i%2;
            ans[a[i]]++;
 
        }
        if(m[a[i]]!=i%2){
            ans[a[i]]++;
            m[a[i]]=i%2;
        }
        debug(m);debug(ans);
    }
    loop(i,1,n+1){
        cout<<ans[i]<<" ";
    }cout<<E;
    
    
 
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("Error.txt", "w", stderr);
    #endif
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}