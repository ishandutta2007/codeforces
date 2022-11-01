#include <string>
#include <vector>
#include <algorithm>
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
set<string> st;
int moz[300];
string imie[3];
int main()
{
    ios_base::sync_with_stdio(0);
    imie[0]="F";
    imie[1]="M";
    imie[2]="S";
    FOR(i,300) moz[i]=0;
    string s[3];
    FOR(i,3) {cin>>s[i];st.insert(s[i]);moz[s[i][0]]++;}
    if (st.sz()==1 || st.sz()==3)
    {
        cout<<"?"<<endl;
        return 0;
    }
    else
    {
        char dwa,jed,wyg;
        if (moz['p']==2) dwa='p';
        if (moz['s']==2) dwa='s';
        if (moz['r']==2) dwa='r';
        if (moz['p']==1) jed='p';
        if (moz['s']==1) jed='s';
        if (moz['r']==1) jed='r';
        if (dwa=='p' && jed=='s')
        {
            FOR(i,3)
            {
                if (s[i][0]=='s') wyg=i;
            }
            cout<<imie[wyg]<<endl;
            return 0;
        }
        if (dwa=='s' && jed=='r')
        {
            FOR(i,3)
            {
                if (s[i][0]=='r') wyg=i;
            }
            cout<<imie[wyg]<<endl;
            return 0;
        }
        if (dwa=='r' && jed=='p')
        {
            FOR(i,3)
            {
                if (s[i][0]=='p') wyg=i;
            }
            cout<<imie[wyg]<<endl;
            return 0;
        }
        cout<<"?"<<endl;
        return 0;
    }
    
    
    return 0;
}