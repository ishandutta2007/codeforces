#include <bits/stdc++.h>

using namespace std;

int main()
{
    //BFS breadth first search
    //O(n+m)
    int N=20000;
    int a,b;
    cin >> a >> b;
    vector<int> d(N+1,-1);
    queue<int> q;
    d[a]=0;
    q.push(a);
    while(!q.empty())
    {
        int x=q.front();
        if(x==b)
        {
            cout << d[x] << "\n";
            break;
        }
        if(x-1>0&&d[x-1]==-1)
        {
            q.push(x-1);
            d[x-1]=d[x]+1;
        }
        if(2*x<=N&&d[2*x]==-1)
        {
            q.push(2*x);
            d[2*x]=d[x]+1;
        }
        q.pop();
    }
    return 0;
}