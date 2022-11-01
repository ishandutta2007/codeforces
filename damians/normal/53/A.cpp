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
string t[1000];
int n;
string s;
set<string> s1,s2;

int main()
{
    ios_base::sync_with_stdio(0);
    cin>>s;
    cin>>n;
    int dl=s.sz();
    FOR(i,n)
    {
        cin>>t[i];
        if (t[i].substr(0,dl)==s) s1.insert(t[i]); else s2.insert(t[i]);
    }
    if (s1.empty())
        cout<<s<<endl;
    else cout<<*(s1.begin())<<endl;
    
    
    return 0;
}