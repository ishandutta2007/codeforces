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
#define sz(x) (int)(x).size()
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define IN(x,y) ((y).find((x))!=(y).end())
#define un(v) v.erase(unique(ALL(v)),v.end())
#define LOLDBG
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

#define MAXLEN 1005000
#define MAX (2*MAXLEN)
map<char,int> ch_link[MAX];
int asize, last, suf_link[MAX], length[MAX];
int topo[MAX];
int stos[MAX*2];
bool odw[MAX];
int is_terminal[MAX];

void mark_terminal_states()
{
    REP(i,1,asize) is_terminal[i]=0;
    int q=last;
    while(q)
    {
        is_terminal[q]=1;
        q=suf_link[q];
    }

}

void topo_sort()//sortuje topologicznie stany (wynik jest od konca)
{
    int st_top=1,akt=0,z;
    stos[0]=1;
    REP(i,1,asize) odw[i]=0;
    while(st_top)
    {
		int u=stos[--st_top];
		if (u<0){topo[akt++]=-u;continue;}
		if (odw[u]) continue;
		odw[u]=1;
		stos[st_top++]=-u;
		for(auto c: ch_link[u])stos[st_top++]=c.se;
	}
}

void init(){ch_link[1].clear();last=1,asize=1;}

void extend(int c)//stany sa numerowane 1..asize, stan 1 to poczatkowy
{
	int q,p;
    p = last;
    last = ++asize;
    length[last] = length[p] + 1;
    ch_link[asize].clear();

    while (p && !IN(c,ch_link[p])) ch_link[p][c] = last, p = suf_link[p];
    if (!p) suf_link[last] = 1;
    else if (length[q = ch_link[p][c]] == length[p] + 1) suf_link[last] = q;
    else
	{
        int clone = ++asize;
        length[clone] = length[p] + 1;
        ch_link[clone] = ch_link[q];
        suf_link[last] = clone;
        suf_link[clone] = suf_link[q];
        suf_link[q] = clone;
        while (p && ch_link[p][c] == q) ch_link[p][c] = clone, p = suf_link[p];
    }
}

int mxpref[MAX];
int nsuf[MAX];
int marker[MAX];


int main()//przyklad wyliczanie ilosci roznych podslow
{
    string s;cin>>s;
    init();
    FOR(i,sz(s)) extend(s[i]);
    topo_sort();
    mark_terminal_states();
    REPD(i,asize-1,0)
    {
        int v=topo[i];
        for(auto it: ch_link[v]) mxpref[it.se]=max(mxpref[it.se],mxpref[v]+1);
    }
    FOR(i,asize)
    {
        int v=topo[i];
        if (sz(ch_link[v])==0) nsuf[v]=1;
        else
        {
            nsuf[v]=is_terminal[v];
            for(auto it: ch_link[v]) nsuf[v]+=nsuf[it.se];
        }
    }
    /*
    REPD(i,asize-1,0)
    {
        int v=topo[i];
        cout<<v<<"\n";
        cout<<"suflink "<<suf_link[v]<<"\n";
        cout<<"nsuf "<<nsuf[v]<<"\n";
        cout<<"length "<<length[v]<<"\n";
        cout<<"mxpref "<<mxpref[v]<<"\n";
        for(auto it: ch_link[v]) cout<<it.fi<<" "<<it.se<<"\n";
        cout<<"\n";
    }*/
    int t;cin>>t;
    FOR(tc,t)
    {
        int res=0;
        string q;cin>>q;
        int n=sz(q);
        q=q+q;
        int state=1;
        int l=0,r=0;
        vi cnted;
        while(l<n)
        {
            if (r-l==n)
            {
                if (marker[state]==0)
                {
                    res+=nsuf[state];
                    marker[state]=1;
                    cnted.pb(state);
                }
            }
            if (r-l<n && ch_link[state].count(q[r]))
            {
                state=ch_link[state][q[r]];
                r++;
            }
            else
            {
                if (r>l)
                {
                    int u=suf_link[state];
                    if (mxpref[u]==r-l-1)state=u;
                    l++;
                }
                else {r++;l++;}
            }
        }
        FOR(i,sz(cnted)) marker[cnted[i]]=0;
        cout<<res<<"\n";
    }



    return 0;
}