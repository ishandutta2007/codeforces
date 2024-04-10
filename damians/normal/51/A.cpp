#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <map>
#include <set>
#include <cmath>
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
#define DBG2(v1,v2) cout<<(v1)<<" - "<<(v2)<<endl;
using namespace std;
set<string> st;
int tab[4][4]={{1,2,3,4},{2,4,1,3},{4,3,2,1},{3,1,4,2}};

int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    int w=0;
    string s,s1,t[3];
    FOR(i,n)
    {
        FOR(j,3) cin>>t[j];
        s=t[0]+t[1];
        if (!IN(s,st))
        {
            w++;
            s1=s;
            FOR(j,4)
            {
                FOR(k,4) s1[k]=s[tab[j][k]-1];
                //DBG(s1);
                st.insert(s1);
            }
        }
        
    }
    cout<<w;
    return 0;
}