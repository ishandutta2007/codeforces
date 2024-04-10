#include <iostream>
#include <algorithm>
using namespace std;
int v1[1005];
int v2[1005];
int v[1005];
bool ap[1005];
int main()
{
    int n,i,j,l=0;
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>v1[i];
    for(i=1;i<=n;i++)
        cin>>v2[i];
    for(i=1;i<=n;i++)
    {
        if(v1[i]==v2[i])
        {
            v[i]=v1[i];
            continue;
        }
        l++;
    }
    if(l==1)
    {
        int p1;
        for(i=1;i<=n;i++)
            {
            ap[v[i]]=1;
            if(!v[i])
                p1=i;
            }
        for(i=1;i<=n;i++)
            if(!ap[i])
            {
                v[p1]=i;
                break;
            }
        for(i=1;i<=n;i++)
            cout<<v[i]<<" ";
        return 0;
    }
    if(l==2)
    {
        int p1,p2,l1,l2;
        for(i=1;i<=n;i++)
            ap[v[i]]=1;
        for(i=1;i<=n;i++)
            if(v[i]==0)
            {
                p1=i;
                break;
            }
        for(i=p1+1;i<=n;i++)
            if(v[i]==0)
            {
                p2=i;
                break;
            }
        for(i=1;i<=n;i++)
            if(ap[i]==0)
            {
                l1=i;
                break;
            }
        for(i=l1+1;i<=n;i++)
            if(ap[i]==0)
            {
                l2=i;
                break;
            }
        int c1,c2;
        ///p1 l1
        v[p1]=l1;
        v[p2]=l2;
        c1=c2=0;
        for(i=1;i<=n;i++)
            {
                if(v1[i]!=v[i])
                    c1++;
                if(v2[i]!=v[i])
                    c2++;
            }
        if(c1==c2 and c1==1)
        {
            for(i=1;i<=n;i++)
                cout<<v[i]<<" ";
            return 0;
        }
        ///p1 l2
        v[p1]=l2;
        v[p2]=l1;
        for(i=1;i<=n;i++)
            cout<<v[i]<<" ";
    }
    return 0;
}