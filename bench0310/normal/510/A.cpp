#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int o=0;o<n;o++)
    {
        for(int i=0;i<m;i++)
        {
            if(!(o&1)) printf("#");
            else if(((o%4)==1&&i==m-1)||((o%4)==3&&i==0)) printf("#");
            else printf(".");
        }
        printf("\n");
    }
    return 0;
}