#include<bits/stdc++.h>
using namespace std;
#define MAX 3000
int n,m,x[MAX],e[MAX];
int main()
{

    while(scanf("%d%d",&n,&m)==2)
    {
        memset(e,0,sizeof e);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&x[i]);
            if(x[i]<=m)e[x[i]]++;
        }
        int change=0;
        if(n%m==0)
        {
            int www=n/m,p=1;
            for(int i=0;i<n;i++)
            {
                while(e[p]>=www)p++;
                if(p>m)break;
                if(x[i]<=m)
                {
                    if(e[x[i]]>www)e[x[i]]--,x[i]=p,e[p]++,change++;
                }
                else x[i]=p,e[p]++,change++;
            }
        }
        else
        {
            int www=(n/m),p=1;
            for(int i=0;i<n;i++)
            {
                while(e[p]>=www)p++;
                if(p>m)break;
                if(x[i]<=m)
                {
                    if(e[x[i]]>www+1)e[x[i]]--,x[i]=p,e[p]++,change++;
                }
                else x[i]=p,e[p]++,change++;
                while(e[p]>=www)p++;
            }
//            printf("p=%d\n",p);
            for(int i=0;(i<n && p<=m);i++)
            {
                if(e[x[i]]==www+1)e[x[i]]--,e[p]++,x[i]=p,change++;
                while(e[p]>=www)p++;

            }
        }
//        cout<<n/m<<endl;
        cout<<n/m<<" "<<change<<endl;
        cout<<x[0];
        for(int i=1;i<n;i++)cout<<" "<<x[i];
        cout<<endl;
    }
    return 0;
}