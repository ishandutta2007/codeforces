#include <bits/stdc++.h>

using namespace std;

#define int long long

inline int add(vector<int>a)
{
    int n=a.size();
    vector<int>b(1,-1);
    for(int i=0;i<n;i++)
    {
        b.push_back(a[i]);
        b.push_back(-1);
    }
    a=b;
    n=2*n+1;
    vector<int>man(n,0);
    int st=-1;
    int dr=-1;
    for(int i=0;i<n;i++)
    {
        if(i<=dr)
        {
            man[i]=min(dr-i+1,man[dr+st-i]);
        }
        while(i-man[i]>=0 && i+man[i]<n && a[i-man[i]]==a[i+man[i]])
        {
            man[i]++;
        }
        if(i+man[i]-1>dr)
        {
            st=i-man[i]+1;
            dr=i+man[i]-1;
        }
    }
    int ans=0LL;
    for(int i=0;i<n;i++)
    {
        if(a[i]<-1)
        {
            continue;
        }
        if(i%2==0)
        {
            ans+=man[i]/2;
        }
        else
        {
            ans+=(man[i]+1)/2;
        }
    }
    return ans;
}

const int N=250+5;

int n,m;
int v[N][N];
int f[N][26];
int odd[N];
int has[N];
int p[N];

inline void clr()
{
    for(int i=0;i<N;i++)
    {
        has[i]=0;
        odd[i]=0;
        for(int j=0;j<26;j++)
        {
            f[i][j]=0;
        }
    }
}

inline void add(int col)
{
    for(int i=1;i<=n;i++)
    {
        f[i][v[i][col]]++;
        has[i]+=p[v[i][col]];
        if(f[i][v[i][col]]%2==1)
        {
            odd[i]++;
        }
        else
        {
            odd[i]--;
        }
    }
}

const int MOD=1000000007;

int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    p[0]=1;
    for(int i=1;i<N;i++)
    {
        p[i]=p[i-1]*(long long)N%MOD;
    }
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        for(int j=1;j<=m;j++)
        {
            v[i][j]=s[j-1]-'a';
        }
    }
    int ans=0LL;
    for(int c1=1;c1<=m;c1++)
    {
        clr();
        for(int c2=c1;c2<=m;c2++)
        {
            add(c2);
            vector<int>lol;
            int last=-2;
            for(int i=1;i<=n;i++)
            {
                if(odd[i]<=1)
                {
                    lol.push_back(has[i]);
                }
                else
                {
                    lol.push_back(last);
                    last--;
                }
            }
            ans+=add(lol);
        }
    }
    cout<<ans<<"\n";
    return 0;
}