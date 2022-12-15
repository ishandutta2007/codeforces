#include <stdio.h>
#include <iostream>
#include <queue>
#include <cstdio>
#include <stack>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string.h>
#include <limits.h>
using namespace std;
struct node
{
    int l,r;
    friend bool operator <(node a, node b)
    {
        if(a.r-a.l==b.r-b.l) return a.l>b.l;
        return a.r-a.l<b.r-b.l;
    }
};
priority_queue <node> q;
int ans[200005];
int main() {
    int T;
    cin>>T;
    while(T--)
    {
        while(!q.empty()) q.pop();
        int n;
        scanf("%d",&n);
        int count=1;
        node t;
        t.l=1;
        t.r=n;
        q.push(t);
        while(!q.empty())
        {
            if(q.top().l==q.top().r) ans[q.top().l]=count++;
            else{
                t=q.top();
                node a;
                ans[(t.l+t.r)/2]=count++;
                if(t.l<(t.l+t.r)/2)
                {
                    a.l=t.l;
                    a.r=(t.l+t.r)/2-1;
                    q.push(a);
                }
                a.l=(t.l+t.r)/2+1;
                a.r=t.r;
                q.push(a);
            }
            q.pop();
        }
        for(int i=1;i<=n;i++) printf("%d ",ans[i]);
        printf("\n");
    }
    return 0;
}