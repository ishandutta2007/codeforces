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
#define sz size()
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

int kier;

int main()
{
    ios_base::sync_with_stdio(0);
    int n;cin>>n;
    int pas,kon;
    cin>>pas>>kon;
    string s;
    cin>>s>>s;
    if (s=="head") kier=-1;
    else kier=1;
    cin>>s;
    if (pas<kon) pas=1;
    else pas=n;
    bool zle=0;
    int mi;
    FOR(i,s.sz)
    {
        if (s[i]=='0')
        {
            kon+=kier;
            if (kon==1) kier=1;
            else if (kon==n) kier=-1;
            if (kon==pas)
            {
                zle=1;
                mi=i+1;
                break;
            }
        }
        else
        {
            if (kier==1) pas=1;
            else pas=n;
            kon+=kier;
            if (kon==1) kier=1;
            else if (kon==n) kier=-1;
            if (kon==pas)
            {
                zle=1;
                mi=i+1;
                break;
            }
        }
    }
    if (zle) cout<<"Controller "<<mi<<endl;
    else cout<<"Stowaway"<<endl;
    return 0;
}