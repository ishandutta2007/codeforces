#include <bits/stdc++.h>

using namespace std;

int main()
{
    array<int,2> a,b;
    scanf("%d%d%d%d",&a[0],&a[1],&b[0],&b[1]);
    int n;
    scanf("%d",&n);
    set<array<int,2>> s;
    for(int i=0;i<n;i++)
    {
        int t,l,r;
        scanf("%d%d%d",&t,&l,&r);
        for(int j=l;j<=r;j++) s.insert({t,j});
    }
    queue<array<int,2>> q;
    map<array<int,2>,int> m;
    m[a]=0;
    q.push(a);
    while(!q.empty())
    {
        array<int,2> e=q.front();
        q.pop();
        for(int i=-1;i<=1;i++)
        {
            for(int j=-1;j<=1;j++)
            {
                array<int,2> f=e;
                f[0]+=i;
                f[1]+=j;
                if(s.find(f)!=s.end()&&m.find(f)==m.end())
                {
                    m[f]=m[e]+1;
                    q.push(f);
                }
            }
        }
    }
    if(m.find(b)!=m.end()) printf("%d\n",m[b]);
    else printf("-1\n");
    return 0;
}