#include <bits/stdc++.h>
using namespace std;
const int NMAX=200000;
int n;
int v[NMAX+5],best[NMAX+5];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>v[i];
    for(int i=1;i<=n;i++)
        best[i]=i-1;
    queue<int>q;
    for(int i=1;i<=n;i++)
    {
        q.push(i);
        while(!q.empty())
        {
            int x=q.front();
            q.pop();
            if(best[x]+1<best[v[x]])
            {
                best[v[x]]=best[x]+1;
                q.push(v[x]);
            }
            if(x-1>=1 and best[x]+1<best[x-1])
            {
                best[x-1]=best[x]+1;
                q.push(x-1);
            }
            if(x+1<=n and best[x]+1<best[x+1])
            {
                best[x+1]=best[x]+1;
                q.push(x+1);
            }
        }
    }
    for(int i=1;i<=n;i++)
        cout<<best[i]<<" ";
    return 0;
}
/**
7
4 4 4 4 7 7 7
**/