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
typedef pair<double,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<double,ll> pdi;
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
#define mod (ll)(1e9+7)
#define eps (1e-9)
#define oo (ll)(0x3f3f3f3f)
#define pi acos(-1)
#define MAXN (ll)(1e5+5)

bool mk[MAXN];
vector<int> g[MAXN];
int level[MAXN],p[MAXN];

int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int n,m,u,v,k;
    cin >> n >> m >> k;
    for(int i=0;i<m;i++)
    {
        cin >> u >> v;
        u--,v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    queue<int> q;
    q.push(0);
    mk[0]=1;
    p[0]=-1;
    int c=-1,c2=-1;
    int fs[2];
    fs[0]=1;
    fs[1]=0;
    while(!q.empty())
    {
        u=q.front();
        q.pop();

        for(auto v : g[u])
        {
            if(!mk[v])
            {
                p[v]=u;
                mk[v]=1;
                q.push(v);
                level[v]=level[u]+1;
                fs[level[v]&1]++;
            }
            else if(v!=p[u])
            {
                c=u;
                c2=v;
            }
        }
    }

    if(c==-1)
    {
        db(1)
        int cant=(k+1)/2;
        if(fs[0]>=(k+1)/2)
        {
            for(int i=0;i<n;i++)
                if(!(level[i]&1) && cant)
                {
                    cout << i+1 << ' ';
                    cant--;
                }
        }
        else
        {
            for(int i=0;i<n;i++)
                if(level[i]&1 && cant)
                {
                    cout << i+1 << ' ';
                    cant--;
                }
        }
        cout << '\n';
        return 0;
    }

    for(int i=0;i<n;i++)
        mk[i]=0;

    vector<int> v1,v2;
    if(level[c]<level[c2])
        swap(c,c2);
    while(level[c]!=level[c2])
    {
        v1.push_back(c);
        c=p[c];
    }
    while(c!=c2)
    {
        v1.push_back(c);
        v2.push_back(c2);
        c=p[c];
        c2=p[c2];
    }
    v1.push_back(c);
//    for(auto v : v1)
//        cout << v+1 << ' ';
//    cout << '\n';
//    for(auto v : v2)
//        cout << v+1 << ' ';
//    cout << '\n';
    reverse(all(v2));
    for(auto y : v2)
        v1.push_back(y);

    map<int,int> mm;
    for(int i=0;i<v1.size();i++)
        mm[v1[i]]=i+1;

    pip p=pip(MAXN,pii(-1,-1));
    for(int i=0;i<v1.size();i++)
    {
        u=v1[i];
        for(auto v : g[u])
        {
            int pos=mm[v];
            if(!pos)
                continue;
            int pu=mm[u];
            int ant=((pu-1)+v1.size()-1)%v1.size()+1;
            int nex=pu%v1.size()+1;
            if(pos!=ant && pos!=nex)
            {
                if(pu<pos)
                    swap(pu,pos);
                int d=min(pu-pos+1,(int)v1.size()-pu+pos+1);
                p=min(p,pip(d,pii(u,v)));
            }
        }
    }

//    cout << p.f  << '\n';
    if(p==pip(MAXN,pii(-1,-1)))
    {
        if(v1.size()<=k)
        {
            db(2)
            db(v1.size())
            for(auto v : v1)
                cout << v+1 << ' ';
            cout << '\n';
        }
        else
        {
            db(1)
            for(int i=0;i<(k+1)/2;i++)
                cout << v1[2*i]+1 << ' ';
            cout << '\n';
        }
        return 0;
    }

    vector<int> cycle1,cycle2;
    int pu=mm[p.s.f];
    int pv=mm[p.s.s];
    pu--,pv--;
    if(pu>pv)
        swap(pu,pv);
    for(int i=0;i<v1.size();i++)
    {
        if(pu<=i && i<=pv)
            cycle1.push_back(v1[i]);
        if(i<=pu || pv<=i)
            cycle2.push_back(v1[i]);
    }

    if(p.f==cycle1.size())
        v1=cycle1;
    else
        v1=cycle2;

//    db("xxx")
    if(v1.size()<=k)
    {
        db(2)
        db(v1.size())
        for(auto v : v1)
            cout << v+1 << ' ';
        cout << '\n';
    }
    else
    {
        db(1)
        for(int i=0;i<(k+1)/2;i++)
            cout << v1[2*i]+1 << ' ';
        cout << '\n';
    }

    return 0;
}
/**
4 4 3
1 2
2 3
3 4
4 1

5 4 5
1 2
1 3
2 4
2 5

6 6 6
4 2
2 5
5 3
3 6
6 1
1 4

7 8 6
6 7
1 2
1 3
2 4
3 5
4 6
5 7
2 3
**/