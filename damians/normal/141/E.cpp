#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>
#include <map>
#include <cstdio>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <cstring>
#define REP(i,x,v)for(int i=x;i<=v;i++)
#define REPD(i,x,v)for(int i=x;i>=v;i--)
#define FOR(i,v)for(int i=0;i<v;i++)
#define FORE(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define REMIN(x,y) (x)=min((x),(y))
#define REMAX(x,y) (x)=max((x),(y))
#define pb push_back
#define sz size()
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define IN(x,y) ((y).find((x))!=(y).end())
#define un(v) v.erase(unique(ALL(v)),v.end())
#define LOLDBG1
#ifdef LOLDBG
#define DBG(vari) cerr<<#vari<<" = "<<vari<<endl;
#define DBG2(v1,v2) cerr<<(v1)<<" - "<<(v2)<<endl;
#else
#define DBG(vari)
#define DBG2(v1,v2)
#endif
#define CZ(x) scanf("%d",&(x));
#define CZ2(x,y) scanf("%d%d",&(x),&(y));
#define CZ3(x,y,z) scanf("%d%d%d",&(x),&(y),&(z));
#define ALL(x) (x).begin(),(x).end()
#define tests int dsdsf;cin>>dsdsf;while(dsdsf--)
#define testss int dsdsf;CZ(dsdsf);while(dsdsf--)
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
template<typename T,typename TT> ostream &operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream &operator<<(ostream &s,vector<T> t){s<<"{";FOR(i,t.size())s<<t[i]<<(i==t.size()-1?"":",");return s<<"}"<<endl; }

int a1[100000],b1[100000];
char c1[100000];
vector<pii> biale, cz;
map<pair<pii,char>,int > mm;



int p[1111];
int n,m;

int szuk(int x)
{
    if (p[x]==x) return x;
    return p[x]=szuk(p[x]);
}

int unia(int x,int y)
{
    p[szuk(x)]=szuk(y);
}

vector<pii> kr[1000];

void wypisz()
{
    vector<pair<pii,char> > v;
    FOR(i,n) FOR(j,kr[i].sz)
    {
        pii p=mp(i,kr[i][j].fi);
        if (p.fi>p.se) swap(p.fi,p.se);
        if (kr[i][j].se==0) v.pb(mp(p,'S'));
        else v.pb(mp(p,'M'));
    }
    sort(ALL(v));
    un(v);
    cout<<n-1<<"\n";
    FOR(i,v.sz)
    {
        if (IN(v[i],mm))
        {
            cout<<mm[v[i]]<<" ";
        }
        else
        {
            swap(v[i].fi.fi,v[i].fi.se);
            cout<<mm[v[i]]<<" ";
        }
    }
    exit(0);
}

int wywal(int a,int b)
{
    FOR(i,kr[a].sz)
    {
        if (kr[a][i].fi==b)
        {
            swap(kr[a][i],kr[a].back());
            kr[a].pop_back();
            break;
        }
    }
    swap(a,b);
    FOR(i,kr[a].sz)
    {
        if (kr[a][i].fi==b)
        {
            swap(kr[a][i],kr[a].back());
            kr[a].pop_back();
            break;
        }
    }
}
void dodaj(int a,int b,int c)
{
    kr[a].pb(mp(b,c));
    kr[b].pb(mp(a,c));
}

bool odw[1000];
vector<pair<pii,int> > stos;
bool jest;

void dfs(int u,int cel)
{
    if (jest) return;
    odw[u]=1;
    if (cel==u)
    {
        jest=1;
        return;
    }
    FORE(i,kr[u])
    {
        if (!odw[i->fi])
        {
            stos.pb(mp(mp(u,i->fi),i->se));
            dfs(i->fi,cel);
            if (!jest) stos.pop_back();
        }
        if (jest) break;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    if (n%2==0)
    {
        cout<<-1;
        return 0;
    }
    FOR(i,m)
    {
        cin>>a1[i]>>b1[i]>>c1[i];
        a1[i]--;
        b1[i]--;
        mm[mp(mp(a1[i],b1[i]),c1[i])]=i+1;
        if (a1[i]==b1[i]) continue;
        if (c1[i]=='S') biale.pb(mp(a1[i],b1[i]));
        else cz.pb(mp(a1[i],b1[i]));
    }
    sort(ALL(biale));
    un(biale);
    sort(ALL(cz));
    un(cz);
    FOR(i,n) p[i]=i;
    int ileb=0;
    FOR(i,biale.sz)
    {
        if (szuk(biale[i].fi)!=szuk(biale[i].se))
        {
            unia(biale[i].fi,biale[i].se);
            kr[biale[i].fi].pb(mp(biale[i].se,0));
            kr[biale[i].se].pb(mp(biale[i].fi,0));
            ileb++;
        }
    }
    DBG(ileb);
    if (ileb<(n-1)/2)
    {
        cout<<-1;
        return 0;
    }
    int ilec=0;
    FOR(i,cz.sz)
    {
        if (szuk(cz[i].fi)!=szuk(cz[i].se))
        {
            unia(cz[i].fi,cz[i].se);
            kr[cz[i].fi].pb(mp(cz[i].se,1));
            kr[cz[i].se].pb(mp(cz[i].fi,1));
            ilec++;
        }
    }
    if (ileb<(n-1)/2 || ileb+ilec!=n-1)
    {
        cout<<-1;
        return 0;
    }
    DBG(ilec);
    FOR(i,cz.sz)
    {
        if (ilec==(n-1)/2)
        {
            wypisz();
        }
        stos.clear();
        jest=0;
        DBG(cz[i]);
        FOR(j,n) odw[j]=0;
        dfs(cz[i].fi,cz[i].se);
        bool wywalilem=0;
        while(stos.sz)
        {
            if (stos.back().se==0)
            {
                wywalilem=1;
                wywal(stos.back().fi.fi,stos.back().fi.se);
                dodaj(cz[i].fi,cz[i].se,1);
                ilec++;
                break;
            }
            stos.pop_back();
        }
    }
    if (ilec==(n-1)/2)
        {
            wypisz();
        }
    cout<<-1;
    

    return 0;
}