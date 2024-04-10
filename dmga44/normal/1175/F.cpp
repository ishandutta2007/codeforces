#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
#define MAXN 300005

int rmq[MAXN][19],lg[MAXN],a[MAXN],last[MAXN];

int query(int l,int r)
{
    if(l>r)
        swap(l,r);
    int p=lg[r-l+1];
    return max(rmq[l][p],rmq[r-(1<<p)+1][p]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    lg[0]=-1;
    for(int i=1;i<MAXN;i++)
        lg[i]=lg[i-1]+!(i&(i-1));

    int n;
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];

    for(int i=0;i<n;i++)
        rmq[i][0]=a[i];
    for(int i=1;i<=lg[n];i++)
        for(int j=0;j+(1<<i)<=n;j++)
            rmq[j][i]=max(rmq[j][i-1],rmq[j+(1<<(i-1))][i-1]);

    int d=0,res=0;
    for(int i=0;i<n;i++)
    {
        if(last[a[i]])
            d=max(d,last[a[i]]);
        last[a[i]]=i+1;
        int p=a[i];
        while(1)
        {
            if(i-p+1<d)
                break;
            int p0=query(i-p+1,i);
            if(p==p0)
            {
                res++;
                p++;
            }
            else
                p=p0;
        }
    }
    db(res)

    return 0;
}