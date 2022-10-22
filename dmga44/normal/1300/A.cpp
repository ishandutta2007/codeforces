#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<ll,pii> pip;
#define MAXN 100005

int a[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int sum=0,res=0;;
        for(int i=0;i<n;i++)
        {
            cin >> a[i];
            if(!a[i])
            {
                a[i]=1;
                res++;
            }
            sum+=a[i];
        }
        if(!sum)
            res++;
        db(res)
    }

    return 0;
}