#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAXN 200005
#define MAXS 450

ll a[MAXN],el_tipo[MAXS];
vector<pii> sq[MAXS];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

//    freopen("t.in","r",stdin);

    int n,q;
    cin >> n >> q;
    for(int i=0;i<n;i++)
        cin >> a[i];

    int x=sqrt(n);
    ll sum=0,s1=0;
    for(int i=0;i<n;i++)
    {
        if(!(i%x))
        {
            s1=0;
            el_tipo[i/x]=sum;
        }
        if(a[i]-s1>=0 && (!i || a[i]>=a[i-1]))
            sq[i/x].push_back(pii(a[i]-s1,i));
        sum+=a[i];
        s1+=a[i];
    }

    for(int i=0;i<MAXS;i++)
        sort(sq[i].begin(),sq[i].end());

    int p,y;
    while(q--)
    {
        cin >> p >> y;
        p--;
        int dif=y-a[p];
        a[p]=y;

        sq[p/x].clear();
        s1=0;
        for(int i=(p/x)*x;i<min(n,(p/x)*x+x);i++)
        {
            if(a[i]-s1>=0 && (!i || a[i]>=a[i-1]))
                sq[p/x].push_back(pii(a[i]-s1,i));
            s1+=a[i];
        }
        sort(sq[p/x].begin(),sq[p/x].end());
        for(int i=(p/x)+1;i<=(n-1)/x;i++)
            el_tipo[i]+=dif;

        int res=-1;
        for(int i=0;i<=(n-1)/x && res==-1 && el_tipo[i]<=1e9;i++)
        {
            int np=lower_bound(sq[i].begin(),sq[i].end(),pii(el_tipo[i],-1))-sq[i].begin();
            if(np<sq[i].size() && sq[i][np].first==el_tipo[i])
                res=sq[i][np].second+1;
        }
        db(res)
    }

    return 0;
}