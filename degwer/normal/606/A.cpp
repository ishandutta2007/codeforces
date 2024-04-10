#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int cnt(int a,int x)
{
    if(a>x)return (a-x)/2;
    else return a-x;
}
int main()
{
    int a,b,c,x,y,z;
    scanf("%d%d%d%d%d%d",&a,&b,&c,&x,&y,&z);
    int t=cnt(a,x)+cnt(b,y)+cnt(c,z);
    if(t>=0)printf("Yes\n");
    else printf("No\n");
}