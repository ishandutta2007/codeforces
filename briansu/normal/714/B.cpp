#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double EPS=0.5;
const ll INF=ll(1e18);
struct ii
{
    int first;
    int second;
    ii(int a,int b){this->first=a;this->second=b;}
};
int main()
{
    ll least=INF,most=-1,dif=-1;
    bool d=false,s=true;
    int n;
    cin>>n;
    for(;n>0;n--)
    {
        ll tmp;
        cin>>tmp;
        if(s &&!(tmp==dif||tmp==most||tmp==least))
        {
        if(tmp>=most&&tmp<=least){most=tmp;least=tmp;}
        else if(most==least)
        {
            if(tmp>=most)most=tmp;
            else if(tmp<=least)least=tmp;
        }
        else if(!d)
        {
            if(tmp>most){dif=most;most=tmp;d=true;}
            else if(tmp<least){dif=least;least=tmp;d=true;}
            else {dif=tmp;d=true;}
        }
        else
        {
            s=false;
        }
        }
    }
    if(s &&(dif*2==most+least||dif==-1))cout<<"YES\n";
    else cout<<"NO\n";
}