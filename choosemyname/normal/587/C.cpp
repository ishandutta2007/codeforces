#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<string>
#include<cmath>
#include<cctype>
#include<ctime>
using namespace std;
const int maxlongint=2147483647;
const int inf=1000000000;
int lch[10000010],rch[10000010],num[10000010],k=0;
int lc[100010][30],n,maxd=1,d[1000010],root[1000010],z;
int getlca()
{
    maxd=(int)(log(maxd+0.5)/log(2))+1;
    int d1,n1;
    for(d1=1;d1<=maxd;d1++)
        for(n1=1;n1<=n;n1++)
            lc[n1][d1]=lc[lc[n1][d1-1]][d1-1];
}
int lca(int i,int j)
{
    int d1;
    if(d[i]<d[j])
        swap(i,j);
    for(d1=maxd;d1>=0;d1--)
        if(d[lc[i][d1]]>=d[j])
            i=lc[i][d1];
    for(d1=maxd;d1>=0;d1--)
        if(lc[i][d1]!=lc[j][d1])
        {
            i=lc[i][d1];
            j=lc[j][d1];
        }
    return i==j?i:lc[i][0];
}
int insert(int i,int j,int l,int r)
{
//  cout<<i<<' '<<j<<' '<<l<<' '<<r<<endl;
    k++;
    int p=k;
    lch[p]=lch[i];
    rch[p]=rch[i];
    num[p]=num[i]+1;
    if(l!=r)
    {
        int mid=(l+r)>>1;
        if(j<=mid)
            lch[p]=insert(lch[i],j,l,mid);
        if(j>mid)
            rch[p]=insert(rch[i],j,mid+1,r);
    }
    return p;
}
int p;
int ask(int i,int j,int k)
{
    int q[10];
    q[0]=root[i];
    q[1]=root[j];
    q[2]=root[lca(i,j)];
    q[3]=root[lc[lca(i,j)][0]];
    if(k>num[q[0]]+num[q[1]]-num[q[2]]-num[q[3]])
        k=num[q[0]]+num[q[1]]-num[q[2]]-num[q[3]];
    printf("%d ",k);
    //cout<<i<<' '<<j<<' '<<lca(i,j)<<' '<<lc[lca(i,j)][0]<<endl;
    for(int y=1;y<=k;y++)
    {
        int oo=y;
        q[0]=root[i];
        q[1]=root[j];
        q[2]=root[lca(i,j)];
        q[3]=root[lc[lca(i,j)][0]];
        int l=1,r=p;
        while(l!=r)
        {
            int t=num[lch[q[0]]]+num[lch[q[1]]]-num[lch[q[2]]]-num[lch[q[3]]],mid=(l+r)>>1,p;
        //  cout<<l<<' '<<r<<'s'<<oo<<' '<<t<<' '<<num[lch[q[0]]]<<' '<<q[1]<<' '<<q[2]<<' '<<q[3]<<endl;
            if(t<oo)
            {
                l=mid+1;
                oo=oo-t;
                for(p=0;p<=3;p++)
                    q[p]=rch[q[p]];
            }
            else
            {
                r=mid;
                for(p=0;p<=3;p++)
                    q[p]=lch[q[p]]; 
            }
        }
        printf("%d ",l);
    }
    printf("\n");
}
map<int,int> mp;    
queue<int> q;
struct Bian
{
    int s,t,last;
}bian[200010];
int maxbian=0,last[100010];
void addbian(int s,int t)
{
    maxbian++;
    bian[maxbian].s=s;
    bian[maxbian].t=t;
    bian[maxbian].last=last[s];
    last[s]=maxbian;
}   
int fmp[1000010],dig[1000010],l[1000010],v[1000010];
vector<int> vec[100010];
int main()
{
    int m,n1,t1,t2,t3;
    scanf("%d%d%d",&n,&p,&m);
    for(n1=1;n1<n;n1++)
    {
        scanf("%d%d",&t1,&t2);
        addbian(t1,t2);
        addbian(t2,t1);
    }
    for(n1=1;n1<=p;n1++)
    {
        scanf("%d",&t1);
        vec[t1].push_back(n1);
    }
    lc[1][0]=0;
    d[1]=1;
    v[1]=1;
    q.push(1);
    for(t3=0;t3<vec[1].size();t3++)
        root[1]=insert(root[1],vec[1][t3],1,p);
    while(!q.empty())
    {
        t1=q.front();
        q.pop();
        for(t2=last[t1];t2;t2=bian[t2].last)
            if(!v[bian[t2].t])
            {
                root[bian[t2].t]=root[t1];
                for(t3=0;t3<vec[bian[t2].t].size();t3++)
                    root[bian[t2].t]=insert(root[bian[t2].t],vec[bian[t2].t][t3],1,p);
                v[bian[t2].t]=1;
                lc[bian[t2].t][0]=t1;
                d[bian[t2].t]=d[t1]+1;
                maxd=max(maxd,d[bian[t2].t]);
                q.push(bian[t2].t);
            }
    }
    //cout<<num[lch[lch[root[2]]]]<<'s'<<endl;
    getlca();
    while(m--)
    {
        scanf("%d%d%d",&t1,&t2,&t3);
        ask(t1,t2,t3);
    }
}