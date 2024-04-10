#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <cstdio>
#include <sstream>
#include <iostream>
#include <cstring>
#define REP(i,x,v)for(int i=x;i<=v;i++)
#define REPD(i,x,v)for(int i=x;i>=v;i--)
#define FOR(i,v)for(int i=0;i<v;i++)
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define pb push_back
#define sz(x) (int)(x).size()
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define IN(x,y) ((y).find((x))!=(y).end())
#define LOLDBG
#ifdef LOLDBG
#define DBG(vari) cout<<#vari<<" = "<<vari<<endl;
#define DBG2(v1,v2) cout<<(v1)<<" - "<<(v2)<<endl;
#else
#define DBG(vari)
#define DBG2(v1,v2)
#endif
#define CZ(x) scanf("%d",&(x));
#define CZ2(x,y) scanf("%d%d",&(x),&(y));
#define ALL(x) (x).begin(),(x).end()
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
template<typename T,typename TT> ostream &operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream &operator<<(ostream &s,vector<T> t){s<<"{";FOR(i,t.size())s<<t[i]<<(i==t.size()-1?"":",");return s<<"}"<<endl; }

const int mxn=100001;

int pres[mxn+1];
int u[mxn+1];
int sito[mxn+2];
vi d[mxn+1];

ll cnt[mxn+1];

ll cnt_coprime(int n)
{
    ll r=0;
    for(int e: d[n]) r+=u[e]*cnt[e];
    return r;
}

void add_cnt(int n,int val)
{
    for(int e: d[n]) cnt[e]+=val;
}


int main()
{
    ios_base::sync_with_stdio(0);

    u[1]=1;
    REP(j,2,mxn)
    {
        if (sito[j])
        {
            int p=sito[j];
            int k=j/p;
            while(k%p==0) {k/=p;}
            u[j]=u[k]*u[j/k];
        }
        else
        {
            for(int x=2*j;x<=mxn;x+=j) {sito[x]=j;}
            u[j]=-1;
        }
    }
    REP(j,1,mxn)
    {
        for(int x=j;x<=mxn;x+=j) d[x].pb(j);
    }
    int n;cin>>n;
    FOR(i,n)
    {
        int a;cin>>a;
        pres[a]=1;
    }
    ll mx=1;
    REP(g,1,mxn)
    {
        vi s;
        for(int i=mxn/g;i>=1;i--)
        {
            if (!pres[i*g]) continue;
            mx=max(mx,i*1LL*g);
            while(cnt_coprime(i))
            {
                mx=max(mx,i*g*1LL*s.back());
                add_cnt(s.back(),-1);
                s.pop_back();
            }
            s.push_back(i);
            add_cnt(i,1);
        }
        while(sz(s))
        {
            add_cnt(s.back(),-1);
            s.pop_back();
        }
    }
    cout<<mx<<"\n";

    return 0;
}