#include<bits/stdc++.h>
using namespace std;

const int N=305;
int n,m,t,a[N][N];

int main()
{
    cin>>t;
    while(t--)
    {
        int flag=1;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) 
        {
            for(int j=1;j<=m;j++)
            {
                scanf("%d",&a[i][j]);
                int tmp=4;
                if(i==1||i==n) tmp--;
                if(j==1||j==m) tmp--;
                if(a[i][j]>tmp) flag=0;
                else a[i][j]=tmp;
            }
        }
        if(flag==0) puts("NO");
        else
        {
            puts("YES");
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=m;j++) printf("%d ",a[i][j]);
                puts("");
            }
        }
    }
}