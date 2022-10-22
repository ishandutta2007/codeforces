#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<pii,pii> ppp;
#define MAXN 200005

int a[MAXN],r[MAXN];
int rmq[MAXN][19],lg[MAXN];

int q(int l,int r)
{
    int d=lg[r-l+1];
    return max(rmq[l][d],rmq[r-(1<<d)+1][d]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    lg[0]=-1;
    for(int i=1;i<MAXN;i++)
        lg[i]=lg[i-1]+!(i&(i-1));

    int n;
    cin >> n;
    int ix=1e9,ax=0;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        a[i+n]=a[i];
        ix=min(ix,a[i]);
        ax=max(ax,a[i]);
    }

    if(ix*2>=ax)
    {
        for(int i=0;i<n;i++)
            cout << -1 << ' ';
        cout << '\n';
        return 0;
    }

    for(int i=0;i<n;i++)
        r[i]=1e6;

    for(int i=0;i<2*n;i++)
        rmq[i][0]=a[i];
    for(int i=1;i<=lg[2*n];i++)
        for(int j=0;j+(1<<i)<=2*n;j++)
            rmq[j][i]=max(rmq[j][i-1],rmq[j+(1<<(i-1))][i-1]);

    int lim=(ax-1)/2;
    for(int i=0;i<n;i++)
        if(a[i]<=lim)
        {
            int res=0,pos=i+n;
            for(int p=(1<<18);p;p>>=1)
                if(pos-p>=0 && q(pos-p,i+n)<=(2*a[i]))
                {
                    res+=p;
                    pos-=p;
                }
            res++;
            r[(i-res+n)%n]=min(r[(i-res+n)%n],res);
        }

    for(int i=0;i<n;i++)
        if(r[i]!=1e6)
        {
            int p=(i-1+n)%n;
            while(r[p]>r[(p+1)%n]+1)
            {
                r[p]=r[(p+1)%n]+1;
                p=(p-1+n)%n;
            }
        }

    for(int i=0;i<n;i++)
        cout << r[i] << ' ';
    cout << '\n';

    return 0;
}