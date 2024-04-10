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
string s;
vector<char> tp;

int main()
{
    cin>>s;
    FOR(i,s.sz())
    {
        if (tp.sz()==0)
            tp.pb(s[i]);
        else if (tp[tp.sz()-1]=='(' && s[i]==')')
            tp.pop_back();
        else
            tp.pb(s[i]);
    }
    cout<<s.sz()-tp.sz();
    return 0;
}