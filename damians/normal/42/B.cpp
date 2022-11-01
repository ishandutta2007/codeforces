#include <string>
#include <vector>
#include <algorithm>
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
using namespace std;
int w[2][2];
int kb[2],kc[2];
int sz[10][10];
string s;

int main()
{
    ios_base::sync_with_stdio(0);
    FOR(i,2)
    {
        cin>>s;
        //DBG(s);
        w[i][0]=s[0]-'a';
        w[i][1]=s[1]-'1';
        //DBG(w[i][0]);
        //DBG(w[i][1]);
    }
    cin>>s;
    kb[0]=s[0]-'a';
    kb[1]=s[1]-'1';
    cin>>s;
    kc[0]=s[0]-'a';
    kc[1]=s[1]-'1';
    FOR(i,10) FOR(j,10) sz[i][j]=0;
    int x,y;
    FOR(ii,2)
    {
        REP(i,w[ii][0]+1,7)
        {
            if (i==kb[0] && w[ii][1]==kb[1]) break;
            sz[i][w[ii][1]]=1;
        }
        REPD(i,w[ii][0]-1,0)
        {
            if (i==kb[0] && w[ii][1]==kb[1]) break;
            sz[i][w[ii][1]]=1;
        }
        REP(j,w[ii][1]+1,7)
        {
            if (w[ii][0]==kb[0] && j==kb[1]) break;
            sz[w[ii][0]][j]=1;
        }
        REPD(j,w[ii][1]-1,0)
        {
            if (w[ii][0]==kb[0] && j==kb[1]) break;
            sz[w[ii][0]][j]=1;
        }
        /*FOR(i,8)
    {
        FOR(j,8) cout<<sz[i][j]<<" ";
        cout<<endl;
    }*/
    }

    REP(i,-1,1) REP(j,-1,1)
    {
        int a=i+kb[0],b=j+kb[1];
        if (a>=0 && a<8 && b>=0 && b<8)
        {
            sz[a][b]=1;
        }
    }
    
    REP(i,-1,1) REP(j,-1,1)
    {
        int a=i+kc[0],b=j+kc[1];
        if (a>=0 && a<8 && b>=0 && b<8)
        {
            if (sz[a][b])// || (a==w[0][0] && b!=w[0][1]) || (a==w[1][0] && b!=w[1][1]) || (b==w[0][1] && a!=w[0][0]) || (b==w[1][1] && a!=w[1][0]) )
            {}
            else
            {
                cout<<"OTHER\n";
                return 0;
            }
        }
    }
    cout<<"CHECKMATE\n";
    
    return 0;
}