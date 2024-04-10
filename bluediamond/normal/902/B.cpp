#include <iostream>
#include <vector>
using namespace std;
const int nmax=10000;
vector<int>v[nmax+5];
int n,color[nmax+5],sum=1;
void dfs(int nod,int actual)
{
    if(color[nod]!=actual)
    {
        sum++;
        dfs(nod,color[nod]);
        return;
    }
    for(int i=0;i<v[nod].size();i++)
        dfs(v[nod][i],actual);
}
int main()
{
    cin>>n;
    for(int i=2;i<=n;i++)
    {
        int a;
        cin>>a;
        v[a].push_back(i);
    }
    for(int i=1;i<=n;i++)
        cin>>color[i];
    dfs(1,color[1]);
    cout<<sum;
    return 0;
}