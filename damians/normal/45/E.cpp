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

vector<string> imie;
vector<string> nazw;

int l1[500];
int l2[500];

int main()
{
    ios_base::sync_with_stdio(0);
    int n;cin>>n;
    FOR(i,n)
    {
        string g;cin>>g;
        imie.pb(g);
    }
    FOR(i,n)
    {
        string g;cin>>g;
        nazw.pb(g);
    }
    sort(ALL(imie));
    sort(ALL(nazw));
    //DBG(imie);
    FOR(i,n) l1[imie[i][0]]++;
    FOR(i,n) l2[nazw[i][0]]++;
    int wyn=0;
    REP(i,'A','Z') wyn+=min(l1[i],l2[i]);
    //DBG(wyn);
    string s;
    FOR(i,n)
    {
        //DBG(s);
        //DBG(imie[i]);
        //DBG(nazw);
        bool ok=0;
        if (l1[imie[i][0]]==min(l2[imie[i][0]],l1[imie[i][0]]))
        {
            FOR(j,nazw.sz)
            {
                if (nazw[j][0]==imie[i][0])
                {
                    ok=1;
                    s+=" "+imie[i]+" "+nazw[j]+",";
                    nazw.erase(nazw.begin()+j);
                    l1[imie[i][0]]--;
                    l2[imie[i][0]]--;
                    break;
                }
            }
        }
        else
        {
            FOR(j,nazw.sz)
        {
            if (l2[nazw[j][0]]!=min(l2[nazw[j][0]],l1[nazw[j][0]]) || nazw[j][0]==imie[i][0])
            {
                s+=" "+imie[i]+" "+nazw[j]+",";
                l2[nazw[j][0]]--;
                nazw.erase(nazw.begin()+j);
                l1[imie[i][0]]--;
                break;
            }
        }
        }
        
        
    }
    while(s[s.sz-1]==',') s=s.substr(0,s.sz-1);
    while(s[0]==' ')s=s.substr(1);
    cout<<s;

    return 0;
}