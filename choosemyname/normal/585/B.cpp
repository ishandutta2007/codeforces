#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<string>
#include<cmath>
#include<cctype>
#include<ctime>
#include<bitset>
using namespace std;
const int maxlongint=2147483647;
const int inf=1000000000;
int can[10][1010][10];
char s[10][1010];
int main()
{
    int T;
    int n,t,n1,n2;
    cin>>T;
    while(T--)
    {
        scanf("%d%d",&n,&t);
        for(n1=1;n1<=3;n1++)
            scanf("%s",s[n1]+1);
        memset(can,0,sizeof(can));
        for(n1=1;n1<=3;n1++)
            if(s[n1][n]=='.')
                for(n2=1;n2<=3;n2++)
                    can[n1][n][n2]=1;
        for(n1=n;n1>1;n1--)
            for(n2=1;n2<=3;n2++)
            {
            //  cout<<n2<<' '<<n1<<' '<<can[n2][n1][1]<<' '<<can[n2][n1][2]<<' '<<can[n2][n1][3]<<endl;
                can[n2][n1-1][3]=can[n2][n1][1];
                can[n2][n1-1][2]=can[n2][n1][3];
                can[n2][n1-1][1]=can[n2][n1][2]|can[n2-1][n1][2]|can[n2+1][n1][2];
                if(s[n2][n1-1]!='.'&&s[n2][n1-1]!='s')
                    can[n2][n1-1][1]=can[n2][n1-1][2]=can[n2][n1-1][3]=0;
                if(s[n2][n1]!='.')
                    can[n2][n1-1][1]=0;
            }
    //  cout<<'s';
        for(n1=1;n1<=3;n1++)
            if(s[n1][1]=='s')
                printf(can[n1][1][1]?"YES\n":"NO\n");
    }
}