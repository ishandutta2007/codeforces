#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
typedef vector<int> vi;
const int mod=998244353;
vi G[maxn];
int sg[maxn];
const int M=512;
int cnt[M];
int dfs(int u)
{
    if(sg[u]!=-1) return sg[u];
    set<int> st;
    for(auto v:G[u])
        st.insert(dfs(v));
    for(int i=0;;i++) if(!st.count(i)) return sg[u]=i;
}
typedef long long ll;
ll quick(ll a,ll b)
{
    ll ret=1;
    while(b)
    {
        if(b&1) ret=ret*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ret;
}
inline ll inv(ll a){return quick(a,mod-2);}
typedef vector<ll> vec;
typedef vector<vec> mat;
int sz;
vec gauss_jordan(const mat& A, const vec& b)
{
    int n=A.size();
    mat B(n,vec(n+1));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            B[i][j]=A[i][j];

    for(int i=0;i<n;i++) B[i][n]=b[i];
    for(int i=0;i<n;i++)
    {
        int pivot=i;
        for(int j=i;j<n;j++)
            if(B[j][i]>B[pivot][i]) pivot=j;
        swap(B[i],B[pivot]);
        //assert(B[i][i]);
        if(!B[i][i]) break;
        ll ib=inv(B[i][i]);
        for(int j=i+1;j<=n;j++) B[i][j]=B[i][j]*ib%mod;
        for(int j=0;j<n;j++)
        {
            if(i!=j)
            {
                for(int k=i+1;k<=n;k++)
                    B[j][k]=(B[j][k]-B[j][i]*B[i][k]%mod+mod)%mod;
            }
        }
    }
    vec x(n);
    for(int i=0;i<n;i++)
    {
        x[i]=B[i][n];
        //cout<<i<<":"<<x[i]<<endl;
    }
    return x;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(sg,-1,sizeof(sg));
    int n,m;
    cin>>n>>m;
    for(int i=0,u,v;i<m;i++)
    {
        cin>>u>>v;
        G[u].push_back(v);
    }
    int nn=1;
    for(int i=1;i<=n;i++)
    {
        //cout<<i<<":"<<dfs(i)<<endl;
        if(dfs(i))
        {
            cnt[dfs(i)]++;
            nn++;
        }
    }
    mat a(M,vec(M));
    ll ninv=inv(nn);
    for(int i=0;i<M;i++)
    {
        a[i][i]=1;
        for(int j=1;j<M;j++)
        {
            a[i^j][i]=(mod-cnt[j]*ninv%mod)%mod;
            //cout<<i<<" "<<j<<":"<<cnt[j]<<endl;
        }
        //a[i][i]=(a[i][i]+ninv)%mod;
        //a[i][i]=(a[i][i]-1+mod)%mod;
    }
    //for(int i=0;i<2;i++) for(int j=0;j<2;j++) cout<<a[i][j]<<" ";
    //cout<<endl;
    vec b(M);
    b[0]=ninv;
    auto ans=gauss_jordan(a,b);
    cout<<((1-ans[0]+mod)%mod)<<'\n';
}