#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;
#define MAXN 200005

ll abi[MAXN],a[MAXN];

void update(int p,ll v)
{
    while(p<MAXN)
    {
        abi[p]+=v;
        p+=(p&-p);
    }
}

ll query(int p)
{
    ll res=0;
    while(p)
    {
        res+=abi[p];
        p-=(p&-p);
    }
    return res;
}

ll dif(int n,int l,int r)
{
    int p1,p2;
    if(n==l)
        p1=1;
    else
    {
        if(n>l)
            p1=l+1;
        else
            p1=l;
    }

    if(n==r)
        p2=1;
    else
    {
        if(n>r)
            p2=r+1;
        else
            p2=r;
    }
    return abs(p1-p2);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        cin >> a[i];
        if(i)
        {
            update(a[i],dif(a[i],a[i],a[i-1]));
            update(a[i]+1,-dif(a[i],a[i],a[i-1]));
//            cout << a[i] << ' ' << dif(a[i],a[i],a[i-1]) << '\n';
//            for(int i=0;i<n;i++)
//                cout << query(i+1) << ' ';
//            db("")

            update(a[i-1],dif(a[i-1],a[i],a[i-1]));
            update(a[i-1]+1,-dif(a[i-1],a[i],a[i-1]));
//            cout << a[i-1] << ' ' << dif(a[i-1],a[i],a[i-1]) << '\n';
//            for(int i=0;i<n;i++)
//                cout << query(i+1) << ' ';
//            db("")

            int mi=min(a[i-1],a[i]);
            int ma=max(a[i-1],a[i]);
            update(mi+1,dif(mi+1,a[i],a[i-1]));
            update(ma,-dif(mi+1,a[i],a[i-1]));
//            cout << mi+1 << ' ' << ma-1 << ' ' << dif(mi+1,a[i],a[i-1]) << '\n';
//            for(int i=0;i<n;i++)
//                cout << query(i+1) << ' ';
//            db("")

            if(mi>1)
            {
                update(1,dif(1,a[i],a[i-1]));
                update(mi,-dif(1,a[i],a[i-1]));
//                cout << 1 << ' ' << mi-1 << ' ' << dif(1,a[i],a[i-1]) << '\n';
//                for(int i=0;i<n;i++)
//                    cout << query(i+1) << ' ';
//                db("")
            }
            if(ma<n)
            {
                update(ma+1,dif(1,a[i],a[i-1]));
                update(n+1,-dif(1,a[i],a[i-1]));
//                cout << ma+1 << ' ' << n << ' ' << dif(1,a[i],a[i-1]) << '\n';
//                for(int i=0;i<n;i++)
//                    cout << query(i+1) << ' ';
//                db("")
            }
//            db("")
        }
    }

    for(int i=0;i<n;i++)
        cout << query(i+1) << ' ';
    cout << '\n';

    return 0;
}