#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef double lf;
const double EPS=1e-4;
const ll INF=ll(1e18);
const int sINF=int(1e8);
typedef pair<int,int> ii;
typedef set<int>::iterator isit;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;
    cin>>n;
    string s;
    cin>>s;
    int i=0;
    for(;i<n&&s[i]=='<';i++);
    int tt=i;
    i=n-1;
    for(;i>=0&&s[i]=='>';i--);
    tt+=n-i-1;
    cout<<tt<<endl;
}