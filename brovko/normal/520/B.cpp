#include <iostream>
#include <queue>

using namespace std;
int n, m, used[100000], v, p[100000];
queue <int> q;

int main()
{
    cin >> n >> m;
    q.push(n);
    p[n]=0;
    while(used[m]==0)
    {
        v=q.front();
        used[v]=1;
        if(v<50000 && v>0)
        {
             if(used[v*2]==0)
             {
                 q.push(v*2);
                 p[v*2]=p[v]+1;
                 used[v*2]=1;
             }

             if(used[v-1]==0)
             {
                 q.push(v-1);
                 p[v-1]=p[v]+1;
                 used[v-1]=1;
             }
        }
        q.pop();
    }
    cout << p[m];
    return 0;
}