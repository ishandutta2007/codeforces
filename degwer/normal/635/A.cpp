#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int d[10][10];
int main()
{
    int mx,my,num,gen;
    scanf("%d%d%d%d",&mx,&my,&num,&gen);
    for(int i=0;i<num;i++)
    {
        int za,zb;
        scanf("%d%d",&za,&zb);
        za--;
        zb--;
        d[za][zb]++;
    }
    int ans=0;
    for(int i=0;i<mx;i++)
    {
        for(int j=i;j<mx;j++)
        {
            for(int k=0;k<my;k++)
            {
                for(int l=k;l<my;l++)
                {
                    int c=0;
                    for(int m=i;m<=j;m++)for(int n=k;n<=l;n++)c+=d[m][n];
                    if(c>=gen)ans++;
                }
            }
        }
    }
    printf("%d\n",ans);
}