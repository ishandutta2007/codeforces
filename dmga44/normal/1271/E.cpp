#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> pip;
#define MAXN 5005

int a[MAXN],b[MAXN],c[MAXN],mi[MAXN];
vector<int> g[MAXN];
bool mk[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen(".in","r",stdin);

    ll n,k;
    cin >> n >> k;
    ll res=0,nn=n,po=1;
    while(n)
    {
        if(n&1)
        {
            if((po-1)+nn%po+1>=k)
                res=max(res,n);
            if(po+((po-1)*2)+(nn%po)+1>=k)
                res=max(res,n-1);
            if(po+((po-1)*2)+po>=k)
                res=max(res,n-3);
        }
        else
        {
            if((po-1)*2+nn%po+1>=k)
                res=max(res,n);
            if(po+(po-1)>=k)
                res=max(res,n-1);
            if(po+((po-1)*2)+po>=k)
                res=max(res,n-2);
        }

        po*=2;
        n/=2;
    }
    db(res)

    return 0;
}