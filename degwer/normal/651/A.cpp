#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    for(int p=0;;p++)
    {
        if(a<b)swap(a,b);
        if(a<=1||b<=0)
        {
            printf("%d\n",p);
            break;
        }
        a-=2;
        b++;
    }
}