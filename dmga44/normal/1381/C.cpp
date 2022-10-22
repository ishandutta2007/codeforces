#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2") //Enable AVX
#pragma GCC optimize("03")

#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
typedef pair<point,int> ppi;
#define mod (ll)(1e9+7)
#define eps (1e-9)
#define oo (ll)(0x3f3f3f3f)
#define pi acos(-1)
#define MAXN (ll)(2e5+5)

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n,x,y;
        cin >> n >> x >> y;
        vector<int> fs(n+2);
        vector<int> ps[n+2];
        vector<int> res(n);
        vector<int> aa(n);
        for(int i=0;i<n;i++)
        {
            int xx;
            cin >> xx;
            aa[i]=xx;
            fs[xx]++;
            ps[xx].push_back(i);
        }

        priority_queue<pii,vector<pii>,less<pii> > pq;
        for(int i=0;i<n+2;i++)
            if(fs[i])
                pq.push(pii(fs[i],i));
        for(int i=0;i<x;i++)
        {
            pii xx=pq.top();
            pq.pop();

            int c=xx.s;
            res[ps[c].back()]=c;
            ps[c].pop_back();
            fs[c]--;
            if(fs[c])
                pq.push(pii(fs[c],c));
        }
//        for(int i=0;i<n;i++)
//            cout << res[i] << ' ';
//        cout <<'\n';
        vector<int> ffaltan(n+2);
        for(int i=0;i<n+2;i++)
            ffaltan[i]=fs[i];

        priority_queue<pii,vector<pii>,greater<pii> > pq2;
        while(!pq.empty())
        {
            pq2.push(pq.top());
            pq.pop();
        }
        vector<int> fs2(n+2);
        for(int i=x;i<y;i++)
        {
            pii xx=pq2.top();
            pq2.pop();

            int c=xx.s;
            fs2[c]++;
            fs[c]--;
            if(fs[c])
                pq2.push(pii(fs[c],c));
        }
//        db("xxx")
        vector<pii> cm;
        for(int i=1;i<n+2;i++)
            if(!ffaltan[i]){
                while(cm.size()<n-y)
cm.push_back(pii(ffaltan[i],i));}
        sort(all(cm));
        for(int i=y;i<n;i++)
            fs2[cm[i-y].s]++;
        priority_queue<pii,vector<pii>,less<pii> > pqp;
        priority_queue<pii,vector<pii>,less<pii> > pqq;
        for(int i=0;i<n+2;i++)
        {
            if(fs2[i])
            {
                pqq.push(pii(fs2[i],i));
//                cout << "pqq " << fs2[i] << ' ' << i << '\n';
            }
            if(ffaltan[i])
            {
                pqp.push(pii(ffaltan[i]+fs2[i],i));
//                cout << "pqp " << ffaltan[i]+fs2[i] << ' ' << i << '\n';
            }
        }

        bool ok=1;
        while(!pqq.empty())
        {
            pii xx=pqp.top();
            pqp.pop();
            if(xx.f!=fs2[xx.s]+ffaltan[xx.s])
            {
                pqp.push(pii(fs2[xx.s]+ffaltan[xx.s],xx.s));
                continue;
            }

            int c=xx.s;
            ffaltan[c]--;
            if(ffaltan[c])
                pqp.push(pii(ffaltan[c]+fs2[c],c));
            int pos=ps[c].back();
//            cout << c << ' ' << pos << '\n';
            ps[c].pop_back();
            if(pqq.top().s==c)
            {
                pii tt=pqq.top();
                pqq.pop();
                if(pqq.empty())
                {
                    ok=0;
                    break;
                }
                pii yy=pqq.top();
                pqq.pop();

                int c2=yy.s;
//                cout << c << ' ' << c2 << '\n';
                fs2[c2]--;
                if(fs2[c2])
                    pqq.push(pii(fs2[c2],c2));
                res[pos]=c2;

                pqq.push(tt);
                continue;
            }
            pii yy=pqq.top();
            pqq.pop();

            int c2=yy.s;
//            cout << c << ' ' << c2 << '\n';
            fs2[c2]--;
            if(fs2[c2])
                pqq.push(pii(fs2[c2],c2));
            res[pos]=c2;
        }

        if(!ok)
            db("NO")
        else
        {
            db("YES")
            for(int i=0;i<n;i++)
                cout << res[i] << ' ';
            cout << '\n';
//            int xa=0;
//            for(int i=0;i<n;i++)
//                if(res[i]==aa[i])
//                    xa++;
//            for(int i=0;i<n+2;i++)
//                fs[i]=0;
//            for(int i=0;i<n;i++)
//                fs[aa[i]]++;
//            vector<int> fsb(n+2);
//            for(int i=0;i<n;i++)
//                fsb[res[i]]++;
//            int xb=0;
//            for(int i=0;i<n+2;i++)
//                xb+=min(fs[i],fsb[i]);
//            cout << xa << ' ' << xb << '\n';
        }
    }

    return 0;
}
/**
7
5 2 4
3 1 1 2 5
5 3 4
1 1 2 1 2
4 0 4
5 5 3 3
4 1 4
2 3 2 3
6 1 2
3 2 1 1 1 1
6 2 4
3 3 2 1 1 1
6 2 6
1 1 3 2 1 1

1
5 2 4
3 1 1 2 5
1
5 3 4
1 1 2 1 2
**/