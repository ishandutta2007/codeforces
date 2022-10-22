#include<bits/stdc++.h>
#define N 100000
using namespace std;
int T,n;
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        priority_queue<int> q;
        for(int i=1,x,p;i<=n;++i)
        {
            scanf("%d",&p);
            if(q.empty() || q.top()<p) q.push(p);
            else
            {
                x=q.top();
                while(!q.empty() && q.top()>p) q.pop();
                q.push(x);
            }
        }
        printf("%d\n",(int)q.size());
    }
    return 0;
}