#include<bits/stdc++.h>
#define N 200000
using namespace std;
int T,n,cnt;
long long w,a[N+5];
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n),w=0,cnt=n;
        for(int i=1;i<=n;++i)
            scanf("%lld",a+i),w+=a[i];
        sort(a+1,a+1+n);
        priority_queue<long long> q;
        q.push(w);
        while(!q.empty())
        {
            w=q.top(),q.pop();
            if(w<a[cnt]) break;
            if(w==a[cnt]) --cnt;
            else q.push(w>>1),q.push((w+1)>>1);
        }
        puts(cnt?"NO":"YES");
    }
    return 0;
}