#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<cassert>
#include<string>
using namespace std;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int ask(int x,int y)
{
    printf("? %d %d\n",x,y);
    fflush(stdout);
    int tmp;scanf("%d",&tmp);
    if(tmp==-1)exit(0);
    return tmp;
}
void answer(int x1,int y1,int x2,int y2){printf("! %d %d %d %d\n",x1,y1,x2,y2);}
int main()
{
    int x=ask(1,1);
    int l=1,r=(int)1e9+1;
    for(;l<r-1;)
    {
        int mid=(l+r)>>1;
        int tmp=ask(mid,1);
        if(tmp==x-(mid-1))l=mid;else r=mid;
    }
    int x1=l,y1=x-(l-1)+1,x2=(int)1e9-(ask((int)1e9,1)-(y1-1)),y2=(int)1e9-(ask(1,(int)1e9)-(x1-1));
    answer(x1,y1,x2,y2);
    return 0;
}