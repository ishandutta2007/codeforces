#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int val;

int n;
int p[1000];
int e[1000];

int lg(int x)
{
    return log2(x);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>val;
    for(int i=2;i<=val;i++)
    {
        int cur=0;
        while(val%i==0)
        {
            val/=i;
            cur++;
        }
        if(cur)
        {
            n++;
            p[n]=i;
            e[n]=cur;
        }
    }
    int ans=1;
    for(int i=1;i<=n;i++)
    {
        ans*=p[i];
    }
    cout<<ans<<" ";
    int co=0;
    for(int i=1;i<=n;i++)
    {
        if(e[i]!=e[1])
        {
            co=1;
        }
        int a=lg(e[i]);
        if((1<<a)!=e[i])
        {
            co=1;
        }
    }
    for(int p=0;p<=100;p++)
    {
        bool ok=1;
        for(int i=1;i<=n;i++)
        {
            if((1<<p)<e[i])
            {
                ok=0;
                break;
            }
        }
        if(ok)
        {
            co+=p;
            break;
        }
    }
    cout<<co<<"\n";
    return 0;
}
/**

**/