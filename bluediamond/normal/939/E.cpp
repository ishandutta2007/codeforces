#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

const int N=500000+5;

int n,q;
ld v[N];

ld res;

ld s=0;
int poz=0;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>q;
    while(q--)
    {
        int t;
        cin>>t;
        if(t==1)
        {
            n++;
            cin>>v[n];
            if(n>=2)
            {
                s-=v[n-1];
            }
            s+=v[n];
            while(poz+1<n)
            {
                ld med=s/(ld)(poz+1);
                ld nmed=(s+v[poz+1])/(ld)(poz+2);
                if(nmed>med) break;
                poz++;
                s+=v[poz];
            }
            res=max(res,v[n]-s/(ld)(poz+1));
      ///      cout<<"\t\t"<<<<"\n";
        }
        else
        {
            cout<<fixed<<setprecision(6)<<res<<"\n";
        }
    }
    return 0;
}