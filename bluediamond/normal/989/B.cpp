#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=2000;

int n,p;
char s[N+5];

int v[N+5];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>p;
    cin.get();
    cin.getline(s,N+5);
    for(int i=0;i<n;i++)
        v[i+1]=s[i];
    bool ok=0;
    for(int i=1;i<=p;i++)
    {
        int a0=0;
        int a1=0;
        int ap=0;
        for(int j=i;j<=n;j+=p)
        {
            if(v[j]=='0')
                a0++;
            else
                if(v[j]=='1')
                    a1++;
                else
                    ap++;
        }
        if(a0!=0 && a1!=0)
        {
            ok=1;
            break;
        }
        if(a0==0 && a1==0)
        {
            if(ap>=2)
            {
                ok=1;
                v[i]='1';
                for(int j=i+p;j<=n;j+=p)
                    v[j]='0';
                break;
            }
            continue;
        }
        if(a0!=0)
        {
            if(ap!=0)
            {
                ok=1;
                for(int j=i;j<=n;j+=p)
                    if(v[j]=='.')
                        v[j]='1';
                break;
            }
        }
        if(a1!=0)
        {
            if(ap!=0)
            {
                ok=1;
                for(int j=i;j<=n;j+=p)
                    if(v[j]=='.')
                        v[j]='0';
                break;
            }
        }
    }
    if(ok==1)
    {
        for(int i=1;i<=n;i++)
        {
            if(v[i]=='.')
                v[i]='1';
            cout<<char(v[i]);
        }
    }
    else
    {
        cout<<"No\n";
    }
    return 0;
}
/**

**/