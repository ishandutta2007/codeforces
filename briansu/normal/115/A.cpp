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

bool b[2000];
vector<int> v[2000];
int g=0,bcnt;

int dfs(int now,int f)
{
    int r=1;
    for(int i=0;i<v[now].size();i++)
    {
        if(v[now][i]!=f)r=max(dfs(v[now][i],now)+1,r);
    }
    return r;
}
int main()
{
    int n;
    cin>>n;
    bcnt=0;
    for(int i=0;i<n;i++)
    {
        int tmp;
        cin>>tmp;
        if(tmp==-1){bcnt++;b[i]=true;}
        else v[tmp-1].push_back(i);
    }
    int i=0;
    while(bcnt)
    {
        if(b[i])
        {
            g=max(dfs(i,-1),g);
            bcnt--;
        }
        i++;
    }
    cout<<g<<endl;
}