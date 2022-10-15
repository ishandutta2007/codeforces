#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=100000+5;

int n;
string s;
int p[N],cnt=0;

int st[N];
int dr[N];

inline int co(int id)
{
    int a=p[id]-st[id];
    int b=dr[id]-p[id];
    return a+b+min(a,b);
}

inline bool ok(int len)
{
    for(int i=1;i<=cnt;i++)
    {
        st[i]=dr[i]=p[i];
    }
    st[1]=p[1];
    for(int i=p[1];i>=1;i--)
    {
        if(s[i]=='*')
        {
            st[1]=i;
        }
    }
    dr[cnt]=p[cnt];
    for(int i=p[cnt];i<=n;i++)
    {
        if(s[i]=='*')
        {
            dr[cnt]=i;
        }
    }
    if(co(1)>len || co(cnt)>len)
    {
        return 0;
    }
    for(int i=1;i<cnt;i++)
    {
        for(int j=p[i]+1;j<p[i+1];j++)
        {
            dr[i]=j;
            if(co(i)>len)
            {
                dr[i]--;
                break;
            }
        }
        for(int j=p[i+1];j>dr[i];j--)
        {
            if(s[j]=='*')
            {
                st[i+1]=j;
            }
        }
    }
    for(int i=1;i<=cnt;i++)
    {
        if(co(i)>len)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    cin>>s;
    s="."+s;
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='P')
        {
            p[++cnt]=i;
        }
    }
    int r=0,pas=(1<<30);
    while(pas)
    {
        if(ok(r+pas)==0)
        {
            r+=pas;
        }
        pas>>=1;
    }
    r++;
    cout<<r<<"\n";
    return 0;
}
/**
**/