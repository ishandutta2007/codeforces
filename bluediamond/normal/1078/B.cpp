#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=100+5;
const int MOD=1000000007;

inline int mul(int a,int b)
{
    return a*(long long)b%MOD;
}

inline int add(int a,int b)
{
    a+=b;
    if(a>=MOD)
    {
        a-=MOD;
    }
    if(a<0)
    {
        a+=MOD;
    }
    return a;
}

inline int expow(int a,int b)
{
    int ans=1;
    while(b)
    {
        if(b&1)
        {
            ans=mul(ans,a);
        }
        a=mul(a,a);
        b>>=1;
    }
    return ans;
}

int fact[N];

inline int comb(int n,int k)
{
    int x=fact[n];
    int y=mul(fact[k],fact[n-k]);
   /// cout<<x<<" , "<<y<<"\n";
    y=expow(y,MOD-2);
    return mul(x,y);
}

int n;
int v[N],f[N];

int cnt[N][N*N]; /// cnt[ cate ] [ sum ]

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    fact[0]=1;
    for(int i=1;i<N;i++)
    {
        fact[i]=mul(fact[i-1],i);
    }
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
        f[v[i]]++;
    }
    sort(v+1,v+n+1);
    if(v[1]==v[n]) /// egale
    {
        cout<<n<<"\n";
        return 0;
    }
    int s=0;
    cnt[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int ant=i-1;ant>=0;ant--)
        {
            for(int cur=s;cur>=0;cur--)
            {
                cnt[ant+1][cur+v[i]]=add(cnt[ant+1][cur+v[i]],cnt[ant][cur]);
            }
        }
        s+=v[i];
    }
   /// cout<<cnt[3][12]<<"\n";
   /// return 0;
    /**for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=10;j++)
        {
            if(cnt[i][j])
            {
                cout<<i<<" , "<<j<<" : "<<cnt[i][j]<<"\n";
            }
        }
    }
    cout<<cnt[2][8]<<"\n"; **/
    int xx=0;
    for(int x=1;x<N;x++)
    {
        if(f[x])
        {
            xx++;
        }
    }
    int ans=0;
    for(int x=1;x<N;x++)
    {
        for(int i=1;i<=f[x];i++)
        {
          ///  cout<<x<<" , "<<i<<" : "<<cnt[i][x*i]<<" , "<<comb(f[x],i)<<"\n";
            if(cnt[i][x*i]==comb(f[x],i))
            {
                ans=max(ans,i);
                if(i==f[x] && xx==2)
                {
                 ///   cout<<"LOL "<<x<<"\n";
                    ans=n;
                }
             ///   cout<<"\t\tA : "<<x<<" , "<<i<<" is = "<<comb(f[x],i)<<"\n";
            }
            if(cnt[n-i][s-x*i]==comb(f[x],i))
            {
                ans=max(ans,i);
                if(i==f[x] && xx==2)
                {
                   /// cout<<"LOL "<<x<<"\n";
                    ans=n;
                }
///cout<<"\t\tA : "<<x<<" , "<<i<<" is = "<<comb(f[x],i)<<"\n";
            }
        }
    }/**
    if(ans==n-1)
    {
        ans=n;
    }**/
    cout<<ans<<"\n";
    return 0;
}
/**

6
1 99 2 2 2 2

**/