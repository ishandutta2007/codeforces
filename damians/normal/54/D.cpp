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
#define FOR(i,v)REP(i,0,(int)(v)-1)
#define FORD(i,v)REPD(i,(int)(v)-1,0)
#define pb push_back
#define sz size
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define IN(x,y) ((y).find((x))!=(y).end())
#define DBG(vari) cout<<#vari<<" = "<<vari<<endl;
#define CZ(x) scanf("%d",&(x));
#define CZ2(x,y) scanf("%d%d",&(x),&(y));
#define ALL(x) (x).begin(),(x).end()
using namespace std;
string p,bin;
int n,k,dl;
int t[200][200];
int pop[200][200];
char uz[200][200];
set<string> pref;
map<pair<int,char>,int> aut;

int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n>>k;
    cin>>p;
    cin>>bin;
    dl=p.sz();
    FOR(i,dl+1) pref.insert(p.substr(0,i));
    string g;
    FOR(i,dl+1) for(char c='a';c<'a'+k;c++)
    {
        g=p.substr(0,i)+c;
        FOR(j,i+2)
        {
            if (IN(g.substr(j),pref)) 
            {
                aut[mp(i,c)]=g.sz()-j;
                //cout<<i<<" "<<c<<" "<<g.sz()-j<<endl;
                break;
            }
        }
    }
    FOR(i,bin.sz()) bin[i]-='0';
    FOR(i,200) FOR(j,200) t[i][j]=0;
    t[0][0]=1;
    REP(i,0,n-1)
    {
        FOR(pref,dl+1)
        {
            if (!t[i][pref]) continue;
            for(char c='a';c<'a'+k;c++)
            {
                if ((i+1-dl)<0 || (aut[mp(pref,c)]<dl && !bin[i+1-dl]) || (aut[mp(pref,c)]==dl && bin[i+1-dl])) 
                {
                    //cout<<i+1<<" "<<aut[mp(pref,c)]<<endl;
                    t[i+1][aut[mp(pref,c)]]=1;
                    pop[i+1][aut[mp(pref,c)]]=pref;
                    uz[i+1][aut[mp(pref,c)]]=c;
                }
            }
        }
    }
    int ok=0;
    int nr;
    FOR(i,dl+1) if (t[n][i]) {ok=1;nr=i;}
    if (ok)
    {
        int k=n;
        string wyn;
        while(k>0)
        {
            wyn+=uz[k][nr];
            nr=pop[k][nr];
            k--;
        }
        reverse(ALL(wyn));
        cout<<wyn<<endl;
    }
    else
        cout<<"No solution"<<endl;
    
    return 0;
}