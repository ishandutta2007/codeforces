#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double EPS=0.5;
const ll INF=ll(1e18);
int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int ro=0,re=0,bo=0,be=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='r')
        {
            if(i%2==0)re+=1;
            else ro+=1;
        }
        else
        {
            if(i%2==0)be+=1;
            else bo+=1;
        }
    }
    //cout<<ro<<" "<<re<<" "<<bo<<" "<<be;
    if((ro==0&&be==0)||(re==0&&bo==0))cout<<0<<endl;
    else{
    //r-o,b-e
    int ch,co;
    ch=min(re,bo);
    co=(re-ch)+(bo-ch);
    int a=ch+co;
    //r-e,b-o
    ch=min(ro,be);
    co=(ro-ch)+(be-ch);
    int b=ch+co;
    cout<<min(a,b)<<endl;
    }
}