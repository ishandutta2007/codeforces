#include <iostream>
#include <vector>
using namespace std;
vector<int>v[100005];
int col[100005];
void dfs1(int nod)
{
    for(int i=0;i<v[nod].size();i++)
        if(col[v[nod][i]]==0)
        {
            col[v[nod][i]]=3-col[nod];
            dfs1(v[nod][i]);
        }
}
int main()
{
    ios_base::sync_with_stdio(0);
    long long n,a,b,n1=0,n2=0,s=0,x;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=1;i<=n;i++)
        s+=v[i].size();
    s/=2;
    col[1]=1;
    dfs1(1);
    for(int i=1;i<=n;i++)
        if(col[i]==1)
            n1++;
        else
            n2++;
    x=n1*n2-s;
    if(x<0)
        x=0;
    cout<<x;
    return 0;
}