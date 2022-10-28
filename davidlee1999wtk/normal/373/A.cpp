#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int cou[12]={0};
int main()
{
    char ju[5][5];
    int k,i,j;
    cin>>k;
    for(i=1;i<=4;i++)
        scanf("%s",ju[i]);
    for(i=1;i<=4;i++)
        for(j=0;j<4;j++)
        {
            if(ju[i][j]!='.')
                cou[ju[i][j]-48]++;
        }
    for(i=1;i<=9;i++)
        if(cou[i]>k*2)
        {
            printf("NO\n");
            return 0;
        }
    printf("YES\n");
    return 0;
}