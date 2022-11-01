#include <string>
#include <vector>
#include <algorithm>
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
using namespace std;
int n;
vector<int> perm;
vector<int> d,f;

bool check()
{
    FOR(i,n)
    {
        if (f[i]!=f[perm[i]])
            return 0;
    }
    return 1;
}

int main()
{
    cin>>n;
    int a;
    perm.resize(n);
    d.resize(n);
    f.resize(n);
    FOR(i,n)
    {
        cin>>a;
        perm[i]=a-1;
        f[i]=i;
    }
    FOR(i,n)
        cin>>d[i];
    FOR(i,n)
    {
        
        int x=i+d[i];
        if (x>=0 && x<n)
        {
            int z=f[x];
            FOR(j,n)
            {
                if (f[j]==z)
                    f[j]=f[i];
            }
        }
        x=i-d[i];
        if (x>=0 && x<n)
        {
            int z=f[x];
            FOR(j,n)
            {
                if (f[j]==z)
                    f[j]=f[i];
            }
        }
    }
    if (check())
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}