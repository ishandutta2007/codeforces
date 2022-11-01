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
#define INF 1000000
using namespace std;
string s1,s2;
int n;
int tab[300][300];


int main()
{
    char a,b;
    int x;
    FOR(i,300) FOR(j,300) tab[i][j]=INF;
    FOR(i,300) tab[i][i]=0;
    cin>>s1;cin>>s2;
    if (s1.sz()!=s2.sz())
    {
        cout<<-1<<endl;
        return 0;
    }
    cin>>n;
    FOR(i,n)
    {
        cin>>a>>b>>x;
        tab[a][b]=min(tab[a][b],x);
    }
    FOR(i,300) FOR(j,300) FOR(k,300)
    {
        if (tab[j][i]+tab[i][k]<tab[j][k]) tab[j][k]=tab[j][i]+tab[i][k];
    }
    int wyn=0;
    FOR(i,s1.sz())
    {
        int l=INF;
        char c1=0,c2;
        for(c2='a';c2<='z';c2++)
        {
            if (l>tab[s1[i]][c2]+tab[s2[i]][c2])
            {
                l=tab[s1[i]][c2]+tab[s2[i]][c2];
                c1=c2;
            }
        }
        if (l<INF)
        {
            wyn+=l;
            s1[i]=c1;
        }
        else
        {
        cout<<-1<<endl;
        return 0;
        }
        
    }
    cout<<wyn<<endl;
    cout<<s1<<endl;
    
    return 0;
}