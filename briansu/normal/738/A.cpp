#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
const double EPS=(1e-6);
const ll INF=ll(1e18);
const int sINF=int(1e8);
typedef pair<ll,ll> ii;
typedef pair<ii,int> iii;
typedef map<int,int>::iterator mpit;
typedef long long ll;
using namespace std;


int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    for(int i=0;i<n-2;i++)
    {
        if(s.substr(i,3)=="ogo")
        {
            int j=i+3;
            s[i]=s[i+1]=s[i+2]='*';
            while(j<n-1&&s.substr(j,2)=="go")
            {
                s[j]=s[j+1]='_';
                j+=2;
            }
        }
    }
    for(int i=0;i<s.length();i++)
    {
        if(s[i]!='_')cout<<s[i];
    }
    cout<<endl;
}