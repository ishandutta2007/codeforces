#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<pii,int> ppi;
#define mod ((ll)(1000000007))
#define m1 ((ll)(1000000006))
#define N 7

ll m[N][N],b[N][N],aux[N][N],aux2[N][N];

void mul()
{
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            aux2[i][j]=0;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            for(int u=0;u<N;u++)
                aux2[i][j]=(aux2[i][j]+(m[i][u]*aux[u][j]))%m1;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            m[i][j]=aux2[i][j];
}

void qp(ll e)
{
    if(e==1)
        return ;
    qp(e/2);
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            aux[i][j]=m[i][j];
    mul();
    if(e&1)
    {
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                aux[i][j]=b[i][j];
        mul();
    }
}

ll qp2(ll b,ll e)
{
    if(!e)
        return 1;
    ll x=qp2(b,e/2);
    x=(x*x)%mod;
    if(e&1)
        x=(x*b)%mod;
    return x;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n,f[4];
    cin >> n;
    for(int i=0;i<4;i++)
        cin >> f[i];

    n-=2;
    ll e[4];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
            for(int u=0;u<4;u++)
                m[j][u]=0;
        m[i+1][0]=1;
        m[1][2]=1;
        m[2][3]=1;
        m[3][1]=1;
        m[3][2]=1;
        m[3][3]=1;
        for(int j=0;j<4;j++)
            for(int u=0;u<4;u++)
                b[j][u]=m[j][u];

        qp(n);
        e[i]=m[3][0];
    }

    for(int j=0;j<N;j++)
        for(int u=0;u<N;u++)
            m[j][u]=0;
    m[4][0]=2;
    m[5][0]=2;
    m[1][2]=1;
    m[2][3]=1;
    m[3][1]=1;
    m[3][2]=1;
    m[3][3]=1;
    m[3][4]=1;
    m[4][4]=1;
    m[4][5]=1;
    m[5][5]=1;
    for(int j=0;j<N;j++)
        for(int u=0;u<N;u++)
            b[j][u]=m[j][u];

    qp(n);
    e[3]=m[3][0];

    ll res=1;
    for(int i=0;i<4;i++)
        res=(res*qp2(f[i],e[i]))%mod;
    db(res)

    return 0;
}