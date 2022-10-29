#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
bool isu(int i)
{
    return i%4==0&&(i%400==0||i%100!=0);
}
int main()
{
    int n;
    scanf("%d",&n);
    int now=0;
    for(int i=n;;i++)
    {
        if(isu(i))now+=2;
        else now++;
        if(now%7==0&&isu(n)==isu(i+1))
        {
            printf("%d\n",i+1);
            return 0;
        }
    }
}