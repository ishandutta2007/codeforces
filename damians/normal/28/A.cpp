#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstring>
#include <set>
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
using namespace std;
set<pair<int,int> > dl;
set<pair<int,int> > dl2;
vector<int> ab;
vector<int> wyn;
int n,m;
int odl(int a,int b,int c,int d)
{
    if (a==c)
        return abs(b-d);
    return abs(a-c);
}
bool go()
{
    wyn.clear();
    int a,b,c,d;
    dl2=dl;
    set<pair<int,int> >:: iterator it;
    FOR(i,n/2)
    {
        a=ab[2*i]+ab[2*i+1];
        it=dl2.upper_bound(mp(a-1,100000000));
        if (it==dl2.end() || (*(it)).fi!=a)
            return 0;
        wyn.pb((*(it)).se);
        dl2.erase(it);
    }
    return 1;
}

int main()
{
    cin>>n>>m;
    wyn.clear();
    int a,b,c,d;
    int a1,b1,c1,d1;
    cin>>a>>b;
    a1=a;b1=b;
    FOR(i,n-1)
    {
        cin>>c>>d;
        ab.pb(odl(a,b,c,d));
        a=c;
        b=d;    
    }
    ab.pb(odl(a1,b1,a,b));
    FOR(i,m)
    {
        cin>>a;
        dl.insert(mp(a,i+1));
    }
    if (go())
    {cout<<"YES\n";
        FOR(i,wyn.sz())
        {
            cout<<-1<<" "<<wyn[i]<<" ";
        }
    }
    else
    {
        int z=ab.back();
        ab.pop_back();
        reverse(ab.begin(),ab.end());
        ab.pb(z);
        reverse(ab.begin(),ab.end());
        if (go())
        {cout<<"YES\n";
            FOR(i,wyn.sz())
            {
                cout<<wyn[i]<<" "<<-1<<" ";
            }
        }
        else
        {
            cout<<"NO";
        }
    }
    
    
    return 0;
}