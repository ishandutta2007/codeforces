#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <stack>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;++i)
#define mp make_pair
#define pb push_back
#define N 200100
int n,q;char to[N];
set<int>dic[3];
int t[3][N];
int lowbit(int x)
{
	return x & -x;
}
void insert(int t[],int p,int x)
{
    ++p;
    while(p<N)
    {
    	t[p]+=x;
    	p+=lowbit(p);
    }
}
int getsum(int t[],int p)
{
    ++p;
    int s=0;
    while (p)
    {
    	s+=t[p];
    	p-=lowbit(p);
    }
    return s;
}
char s[N];
int a[N];
int get(){
    int ret=0;
    for(int i=0;i<3;++i)
    {
        int x=(i+2)%3;
        int y=i;
        int z=(i+1)%3;
        int x0,y0,x1,y1;
        if(!dic[z].size())x0=n+1;else x0=*(dic[z].begin());
        if(!dic[x].size())y0=n+1;else y0=*(dic[x].begin());
        if(!dic[z].size())x1=0;else x1=*(dic[z].rbegin());
        if(!dic[x].size())y1=0;else y1=*(dic[x].rbegin());
        ret+=getsum(t[y],n);
        if(x0<=y0)ret-=getsum(t[y],y0)-getsum(t[y],x0);
        if(y1<=x1)ret-=getsum(t[y],x1)-getsum(t[y],y1);
        if(x0<=y0&&y1<=x1)
        {
            int x2=max(x0,y1),y2=min(y0,x1);
            if(x2<=y2)ret+=getsum(t[y],y2)-getsum(t[y],x2);
        }
    }
    return ret;
}
int main()
{
    to['R']=0,to['P']=1,to['S']=2;
    cin>>n>>q;
    scanf("%s",s+1);
    for(int i=1;i<=n;i++)a[i]=to[s[i]];
	for(int i=1;i<=n;i++){ insert(t[a[i]],i,1),dic[a[i]].insert(i); }
	cout<<get()<<endl;
    while (q--)
    {
        int x;
        char w[10];
        scanf("%d",&x);
        scanf("%s",w+1);
        insert(t[a[x]],x,-1);
        dic[a[x]].erase(x);
        a[x]=to[w[1]];
        insert(t[a[x]],x,1);
        dic[a[x]].insert(x);
        printf("%d\n",get());
    }
    return 0;
}