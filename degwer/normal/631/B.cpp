#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int,int>pii;
pii d1[5000],d2[5000];
int main()
{
    int mx,my,query;
    scanf("%d%d%d",&mx,&my,&query);
    for(int i=0;i<query;i++)
    {
        int za,zb,zc;
        scanf("%d%d%d",&za,&zb,&zc);
        if(za==1)d1[zb-1]=make_pair(zc,i+1);
        else d2[zb-1]=make_pair(zc,i+1);
    }
    for(int i=0;i<mx;i++)
    {
        for(int j=0;j<my;j++)
        {
            if(j!=0)printf(" ");
            if(d1[i].second>d2[j].second)printf("%d",d1[i].first);
            else printf("%d",d2[j].first);
        }
        printf("\n");
    }
}