#include <bits/stdc++.h>
#define endl '\n'
#define db(x) cout << x << endl;
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
#define MAXN 25

int a[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int res=0,f=1;
    int n,aa,b;
    cin >> n >> aa >> b;
    for(int i=0;i<n;i++)
        cin >> a[i];
    for(int i=0;i<n/2;i++)
    {
        if(a[i]==a[n-i-1])
        {
            if(a[i]==2)
                res+=min(2*aa,2*b);
        }
        else
        {
            if(a[i]==2 || a[n-i-1]==2)
            {
                if(a[i]==0 || a[n-i-1]==0)
                    res+=aa;
                else
                    res+=b;
            }
            else
                f=0;
        }
    }
    if(n&1 && a[n/2]==2)
        res+=min(aa,b);

    if(!f)
        res=-1;
    db(res)

    return 0;
}