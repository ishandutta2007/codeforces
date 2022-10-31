#include<bits/stdc++.h>
using namespace std;
int n,m,ans,k;
struct node{
    int sz,mx[15],mn[15];
    friend bool operator < (node a,node b)
	{
        for(int i=1;i<=k;i++)
            if(a.mx[i]>b.mn[i]) return 0;
        return 1;
    }   
}a;
set<node>s;
set<node>::iterator it;
signed main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
	{
        a.sz=1;
        for(int j=1;j<=k;j++)
		{
			scanf("%d",&a.mn[j]);
			a.mx[j]=a.mn[j];
		}
        it=s.find(a);
        while(it!=s.end())
		{
            a.sz+=(*it).sz;
            for(int j=1;j<=k;j++)
			{
                a.mx[j]=max(a.mx[j],(*it).mx[j]);
                a.mn[j]=min(a.mn[j],(*it).mn[j]);
            }
            s.erase(it);
            it=s.find(a);
        }
        s.insert(a);
        it=s.end();
        --it;
        printf("%d\n",(*it).sz);
    }
    return 0;
}