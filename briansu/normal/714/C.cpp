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
    int T;
    cin>>T;
    map<int,int> m;
    for(;T>0;T--)
    {
        char c;
        ll n;
        cin>>c>>n;
        if(c=='?')cout<<(m.count(n)?m[n]:0)<<endl;
        else
        {
            int tmp=0;
            char s[20];stringstream ss;
            ss<<n;ss>>s;
            for(int i=0;s[i]!='\0';i++)tmp=tmp*10+((s[i]-'0')%2);
            if(c=='+'){if(m.count(tmp))m[tmp]++;else m[tmp]=1;}
            else m[tmp]--;
        }
    }
}