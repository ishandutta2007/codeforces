#include<set>
#include<map>
#include<list>
#include<queue>
#include<stack>
#include<string>
#include<math.h>
#include<time.h>
#include<vector>
#include<bitset>
#include<memory>
#include<utility>
#include<fstream>
#include<stdio.h>
#include<sstream>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
char oper[100005];
int oper_num[100005];
int a[100005];
map<int,int> ma;
long long val[1<<18][5];
int size[1<<18];
void change(int num,int l,int r,int k,int t,int x)
{
    if (l==r-1)
    {
        val[num][0]+=x*t;
        size[num]+=x;
        return;
    }
    int mid=(l+r)/2;
    if (k<mid)
    {
        change(num*2+1,l,mid,k,t,x);
    }
    else
    {
        change(num*2+2,mid,r,k,t,x);
    }
    size[num]=size[num*2+1]+size[num*2+2];
    int i;
    for (i=0;i<5;i++)
    {
        val[num][i]=val[num*2+1][i]+val[num*2+2][((i-size[num*2+1])%5+5)%5];
    }
}
long long query(int num,int l,int r,int l0,int r0)
{
    return val[num][2];
}
int main()
{
    ios::sync_with_stdio(false);
    int n;
    scanf("%d",&n);
    int i;
    int t=0;
    for (i=0;i<n;i++)
    {
        static char opers[1005];
        scanf("%s",opers);
        oper[i]=opers[0];
        if (oper[i]!='s')
        {
            scanf("%d",&oper_num[i]);
            a[t++]=oper_num[i];
        }
    }
    sort(a,a+t);
    t=unique(a,a+t)-a;
    for (i=0;i<t;i++)
    {
        ma[a[i]]=i;
    }
    for (i=0;i<n;i++)
    {
        if (oper[i]=='s')
        {
            cout<<query(0,0,n,0,n)<<'\n';
        }
        else if (oper[i]=='a')
        {
            change(0,0,n,ma[oper_num[i]],oper_num[i],1);
        }
        else
        {
            change(0,0,n,ma[oper_num[i]],oper_num[i],-1);
        }
    }
    return 0;
}