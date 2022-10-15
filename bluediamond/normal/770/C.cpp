#include <iostream>
#include <vector>
using namespace std;
vector<int>v[100005];
bool sl[100005];
int sol[100005];
int t[100005];
int n,fl,y=0;
void dfs(int nod,int lenght,int n)
{
    if(lenght>n)
        fl=1;
    if(!fl)
    {
        for(int j=0;j<v[nod].size();j++)
            if(!sl[v[nod][j]])
                dfs(v[nod][j],lenght+1,n);
        if(!sl[nod])
            sol[++y]=nod;
        sl[nod]=1;
    }
}
int main()
{
    int n,k,i,j,a,b;
    cin>>n>>k;
    for(i=1;i<=k;i++)
        cin>>t[i];
    for(i=1;i<=n;i++)
    {
        cin>>a;
        for(j=1;j<=a;j++)
        {
            cin>>b;
            v[i].push_back(b);
        }
    }
    cout<<"\n\n";
    for(i=1;i<=k;i++)
    {
        dfs(t[i],1,n);
        if(fl)
        {
            cout<<-1;
            return 0;
        }
    }
    cout<<y<<"\n";
    for(i=1;i<=y;i++)
        cout<<sol[i]<<" ";
    return 0;
}