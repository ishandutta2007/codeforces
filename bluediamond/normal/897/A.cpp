#include <iostream>
#include <cstdio>
using namespace std;
const int nm=100;
char ch;
int n,m;
int v[nm+5];
int main()
{
    scanf("%d%d",&n,&m);
    scanf("\n");
    for(int i=1;i<=n;i++)
    {
        scanf("%c",&ch);
        v[i]=ch;
    }
    int st,dr;
    char c1,c2;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d %c %c",&st,&dr,&c1,&c2);
        for(int j=st;j<=dr;j++)
            if(v[j]==c1)
                v[j]=c2;
    }
    for(int i=1;i<=n;i++)
        printf("%c",v[i]);
    return 0;
}