#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
#define MAX 25
#define REP(x,y) for(int x=0;x<y;x++)
//#define REP(x,y,z) for(int x=y;x<z;x++)
#define MEM(x,y) memset(x,y,sizeof x)
#define a first
#define b second
int n,m,x[MAX][MAX];
int main()
{
    while(scanf("%d%d",&n,&m)==2)
    {
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                scanf("%d",&x[i][j]);
        int ans=0;
        for(int qq=0;qq<m;qq++)
        for(int ww=0;ww<m;ww++)
        {
            if(ans)break;
            int ha=1;
            for(int i=0;i<n;i++)
            {
                swap(x[i][qq],x[i][ww]);
                int q=0;
                for(int j=0;j<m;j++)
                {
                    if(x[i][j]!=j+1)
                    {
                        q++;
                    }
                }
//                cout<<q<<endl;
                swap(x[i][qq],x[i][ww]);
                if(q!=0 && q!=2){ha=0;break;}
            }
            if(ha)ans=1;
        }

        if(ans)puts("YES");
        else puts("NO");
    }
    return 0;
}