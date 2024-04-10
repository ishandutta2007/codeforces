#include <bits/stdc++.h>
#define endl '\n'
#define db(x) cout << x << endl;
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,k;
    cin >> n >> k;
    int x=n-2-2*k;
    if(x<0)
    {
        db(1)
        db((n/2)+1)
    }
    else
    {
        int div=x/(1+2*k);
        int res=x%(1+2*k);
        int st=1,fi=n;
        if(res>k)
        {
            st+=k;
            fi-=(res-k);
        }
        else
            st+=res;
        db(2+div)
        for(int i=st;i<=n;i+=(1+2*k))
            cout << i << ' ';
        cout << '\n';
    }

    return 0;
}