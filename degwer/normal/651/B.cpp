#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int dat[1000];
int main()
{
    int num;
    scanf("%d",&num);
    for(int i=0;i<num;i++)
    {
        int z;
        scanf("%d",&z);
        dat[z-1]++;
    }
    int maxi=0;
    for(int i=0;i<1000;i++)maxi=max(maxi,dat[i]);
    printf("%d\n",num-maxi);
}