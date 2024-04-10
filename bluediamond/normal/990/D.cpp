#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=1000;

int n,a,b;

int v[N+5][N+5];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>a>>b;
    if(a!=1 && b!=1)
    {
        cout<<"NO\n";
        return 0;
    }
    if(n==1)
    {
        cout<<"YES\n";
        cout<<"0\n";
        return 0;
    }
    if(a==1 && b==1)
    {
        if(n<=3)
            cout<<"NO\n";
        else
        {
            cout<<"YES\n";
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=n;j++)
                    if(i==j+1 || j==i+1)
                        cout<<"1";
                    else
                        cout<<"0";
                cout<<"\n";
            }
            return 0;
        }
        return 0;
    }
    cout<<"YES\n";
    if(a!=1)
    {
        int cnt=2*n;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
                if(cnt>2*a && (i==j+1 || j==i+1))
                {
                    cnt--;
                    cout<<"1";
                }
                else
                    cout<<"0";
            cout<<"\n";
        }
        return 0;
    }
    int cnt=2*n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j)
            {
                cout<<"0";
                continue;
            }
            if(cnt>2*b && (i==j+1 || j==i+1))
            {
                cnt--;
                cout<<"0";
            }
            else
                cout<<"1";
        }
        cout<<"\n";
    }
    return 0;
}