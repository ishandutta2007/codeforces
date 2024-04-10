#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
const double EPS=1e-8;
const ll INF=ll(1e18);
const int sINF=int(1e8);
typedef pair<int,int> ii;
typedef set<int>::iterator isit;
int main()
{
    map<string,int> m;
    m["monday"]=0;
    m["tuesday"]=1;
    m["wednesday"]=2;
    m["thursday"]=3;
    m["friday"]=4;
    m["saturday"]=5;
    m["sunday"]=6;
    string a,b;
    cin>>a>>b;
    int x=m[a],y=m[b];
    int d[3]={28,30,31};
    for(int i=0;i<3;i++)
    {
        if((x+d[i])%7==y){cout<<"YES"<<endl;return 0;}
    }
    cout<<"NO"<<endl;

}