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
string s;
vector<int> w;
int main()
{
    ios_base::sync_with_stdio(0);
    string s1,t;
    int tp=0;
    vector<int> v;
    while(cin>>s1)
    {
        s=s+s1;
    }
    FOR(i,s.sz())
    {
        if (s[i]=='>' || s[i]=='<') s[i]=' ';
    }
    //DBG(s);
    stringstream ss(s);
    while(ss>>t)
    {
        //DBG(t);
        if (t[2]=='b')
        {
            v.pb(0);
            
        }
        else if (t[2]=='d')
        {
            v.back()++;
        }
        else if (t[3]=='b')
        {
            w.pb(v.back());
            v.pop_back();
        }
    }
    sort(w.begin(),w.end());
    FOR(i,w.sz()) cout<<w[i]<<" ";
    return 0;
}