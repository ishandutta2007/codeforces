#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
const double EPS=1e-4;
const ll INF=ll(1e18);
const int sINF=int(1e9);
typedef pair<int,int> ii;
typedef map<int,int>::iterator mpit;
typedef long long ll;
using namespace std;

int n,b;
set<int> s;
vector<int> ans;
int main()
{
    cin>>n>>b;

    for(int i=0;i<n;i++)
    {
        int tmp;
        cin>>tmp;
        s.insert(tmp);
    }
    for(int i=1;i<sINF;i++)
    {
        if(b<i)break;
        if(!s.count(i))
        {
            b-=i;
            ans.push_back(i);
        }
    }
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++)
    {
        cout<<(i==0?"":" ")<<ans[i];
    }
    cout<<endl;

}