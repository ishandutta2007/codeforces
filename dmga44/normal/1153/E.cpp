#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii,int> ppi;
#define MAXN 1005

int a[MAXN],b[MAXN];

int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int n;
    cin >> n;
    for(int i=1;i<n;i++)
    {
        cout << "? " << i << " 1 " << i << ' ' << n << '\n';
        cout.flush();
        cin >> a[i];
    }

    for(int i=1;i<n;i++)
    {
        cout << "?" << " 1 " << i << ' ' << n << ' ' << i << '\n';
        cout.flush();
        cin >> b[i];
    }

    vector<int> pa,pb;
    for(int i=1;i<=n;i++)
    {
        if(i==n)
        {
            a[i]=a[i]-a[i-1];
            b[i]=b[i]-b[i-1];
        }
        if(a[i]&1)
            pa.push_back(i);
        if(b[i]&1)
            pb.push_back(i);
        a[i]=a[i]-a[i-1];
        b[i]=b[i]-b[i-1];
    }

    if(pa.size()==2)
    {
        if(pb.size()==2)
        {
            int x[2][2];
            cout << "? " << pa[0] << ' ' << pb[0] << ' ' << pa[0] << ' ' << pb[0] << '\n';
            cout.flush();
            cin >> x[0][0];

            cout << "? " << pa[1] << ' ' << pb[0] << ' ' << pa[1] << ' ' << pb[0] << '\n';
            cout.flush();
            cin >> x[1][0];

            cout << "? " << pa[0] << ' ' << pb[1] << ' ' << pa[0] << ' ' << pb[1] << '\n';
            cout.flush();
            cin >> x[0][1];

            cout << "? " << pa[1] << ' ' << pb[1] << ' ' << pa[1] << ' ' << pb[1] << '\n';
            cout.flush();
            cin >> x[1][1];
            cout << "!";
            for(int i=0;i<2;i++)
                for(int j=0;j<2;j++)
                    if(x[i][j]==1)
                        cout << ' ' <<  pa[i] << ' ' << pb[j];
            cout << '\n';
            cout.flush();
        }
        else
        {
            int res=0;
            for(int i=(1<<9);i;i>>=1)
            {
                if(res+i>n)
                    continue;
                int r1=res+i;
                cout << "? " << pa[0] << ' ' << 1 << ' ' << pa[0] << ' ' << r1 << '\n';
                cout.flush();
                int xxx;
                cin >> xxx;
                if((xxx&1)==0)
                    res=r1;
            }
            res++;
            int rr1=res;
            res=0;
            for(int i=(1<<9);i;i>>=1)
            {
                if(res+i>n)
                    continue;
                int r1=res+i;
                cout << "? " << pa[1] << ' ' << 1 << ' ' << pa[1] << ' ' << r1 << '\n';
                cout.flush();
                int xxx;
                cin >> xxx;
                if((xxx&1)==0)
                    res=r1;
            }
            res++;
            int rr2=res;
            cout << "! " << pa[0] << ' ' << rr1 << ' ' << pa[1] << ' ' << rr2 << '\n';
            cout.flush();
        }
    }
    else
    {
        int res=0;
        for(int i=(1<<9);i;i>>=1)
        {
            if(res+i>n)
                continue;
            int r1=res+i;
            cout << "? " << 1 << ' ' << pb[0] << ' ' << r1 << ' ' << pb[0] << '\n';
            cout.flush();
            int xxx;
            cin >> xxx;
            if((xxx&1)==0)
                res=r1;
        }
        res++;
        int rr1=res;
        res=0;
        for(int i=(1<<9);i;i>>=1)
        {
            if(res+i>n)
                continue;
            int r1=res+i;
            cout << "? "  << 1 << ' ' << pb[1] << ' ' << r1 << ' '<< pb[1] << '\n';
            cout.flush();
            int xxx;
            cin >> xxx;
            if((xxx&1)==0)
                res=r1;
        }
        res++;
        int rr2=res;
        cout << "! " << rr1 << ' ' << pb[0] << ' ' << rr2 << ' ' << pb[1] << '\n';
        cout.flush();
    }

    return 0;
}