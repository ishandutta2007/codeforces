#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
const double EPS=1e-8;
const ll INF=ll(1e18);
typedef pair<int,ll> ill;
int main()
{
    int n;
    cin>>n;
    int p[n];
    for(int i=0;i<n;i++)
    {
        cin>>p[i];
    }
    bool can=true;
    cin.ignore(1);
    for(int k=0;k<n;k++)
    {
        int cnt=0;
        string s;

        getline(cin,s);

        for(int i=0;i<s.length();i++)
        {
            string sub=s.substr(i,1);
            //cout<<sub;
            if(sub=="a"||sub=="e"||sub=="i"||sub=="o"||sub=="u"||sub=="y")
            {
                cnt++;
            }
        }
        //cout<<cnt<<endl;
        if(cnt!=p[k])can=false;
    }
    if(can)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
}