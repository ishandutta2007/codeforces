#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<double,ll> pdi;
typedef pair<string,ll> psi;
typedef pair<int,pii> pip;
typedef pair<pii,pii> ppp;
#define MAXN 5005

int res[MAXN],level[MAXN],sons[MAXN],rr[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n,d;
        cin >> n >> d;
        int mi=0,po=3,dp=1;
        while(po<=n)
        {
            mi+=(po/2+1)*dp;
            dp++;
            po<<=1;
            po++;
        }
        po>>=1;
        mi+=(n-po)*dp;

        int ma=((n)*(n-1))/2;
        if(mi<=d && d<=ma)
        {
            db("YES")
            ll sum=mi;
            for(int i=2;i<=n;i++)
            {
                res[i]=i/2;
                level[i]=level[i/2]+1;
            }

            int last=-1;
            int nn=n;
            while(nn!=(nn&-nn))
                nn-=(nn&-nn);
            last=nn;
            for(int i=n;i>=3;i--)
            {
//                cout << i << ' ' << sum << '\n';
                if(__builtin_popcount(i)==1)
                    continue;
                if(sum==d)
                    break;
                if(sum+(level[last]+1-level[i])<=d)
                {
                    res[i]=last;
                    sum+=(level[last]+1-level[i]);
                    level[i]=level[last]+1;
                    last=i;
                }
                else
                {
                    int pos=d-sum+level[i]-1;
                    set<int> av;
                    vector<int> sons(n+1);
                    for(int j=1;j<=n;j++)
                        if(level[j]==pos && i!=j)
                            av.insert(j);
                    for(int j=2;j<=n;j++)
                        sons[res[j]]++;

                    ll ok=-1;
                    for(auto y : av)
                        if(sons[y]!=2)
                            ok=y;
                    last=ok;

                    res[i]=last;
                    sum+=(level[last]+1-level[i]);
                    level[i]=level[last]+1;
                    last=i;
                }
            }
            for(int i=2;i<=n;i++)
                cout << res[i] << ' ';
            cout << '\n';
        }
        else
            db("NO")
    }

    return 0;
}
/**
10
10 19
10 20
10 21
10 22
10 23
10 24
10 25
10 26
10 27
10 28
**/