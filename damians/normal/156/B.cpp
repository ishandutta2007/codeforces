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

int tak[100001],nie[100001];
int odp[100001];
set<int> klamca;

int main()
{
    ios_base::sync_with_stdio(0);
    int n,m;
    cin>>n>>m;
    int a;
    int iletak=0,ilenie=0;
    FOR(i,n)
    {
        cin>>a;
        odp[i]=a;
        if (a<0)
        {
            a=abs(a);a--;
            nie[a]++;
            ilenie++;
        }
        else
        {
            a=abs(a);a--;
            tak[a]++;
            iletak++;
        }
    }
    FOR(i,n)
    {
        int prawda=tak[i]+ilenie-nie[i];
        if (prawda==m)
        {
            klamca.insert(i);
        }
    }
    FOR(i,n)
    {
        int a=odp[i];
        if (a<0)
        {
            a=abs(a);a--;
            if (!IN(a,klamca))
            {
                cout<<"Truth\n";
            }
            else if (klamca.sz==1)
            {
                cout<<"Lie\n";
            }
            else cout<<"Not defined\n";
        }
        else
        {
            a=abs(a);a--;
            if (IN(a,klamca))
            {
                if (klamca.sz==1) cout<<"Truth\n";
                else cout<<"Not defined\n";
            }
            else cout<<"Lie\n";
        }
    }

    return 0;
}