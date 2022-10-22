#include<bits/stdc++.h>
#define N 100000
using namespace std;
int T,n,b[N+5],a[N+5],cnt,p,num[2];
vector<int> v[N+5];
int main()
{
    for(scanf("%d",&T);T--;)
    {
        scanf("%d",&n),cnt=num[0]=num[1]=0;
        for(int i=0;i<=n+1;++i) v[i].clear();
        for(int i=1;i<=n;++i) scanf("%d",b+i),v[b[i]].push_back(i);
        int last=v[0].empty()?n+1:0;
        bool w=last?1:0;
        while(~last)
        {
            int p=-1;num[w^=1]+=v[last].size();
            for(int x:v[last])
                if(v[x].empty()) a[++cnt]=x;
                else p=x;
            a[++cnt]=last=p;
        }
        printf("%d\n",num[0]);
        for(int i=1;i<=n;++i) printf("%d%c",a[i]," \n"[i==n]);
    }
    return 0;
}