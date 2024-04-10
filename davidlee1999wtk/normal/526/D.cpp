#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cstdlib>
#include<string>
#include<bitset>
#define INF 1000000000
#define N 1000005
#define fi first
#define se second
#define debug(x) cout<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
int f[N];
char s[N];
int main()
{
    int n,k,i,j,t,x,y;
    cin>>n>>k;
    scanf("%s",s+1);
    f[1]=f[2]=1;
    for(i=2;i<=n;i++)
    {
        j=f[i];
        while(j!=1&&s[j]!=s[i])
            j=f[j];
        f[i+1]=s[j]==s[i]?j+1:1;
    }
    for(i=1;i<=n;i++)
    {
        j=i-(f[i+1]-1);
        t=i/j;
        if(i%j!=0)
        {
            x=t%k;
            //if(t/k-x>0)
            if(t>(LL)(k+1)*x)
            {
                //if(n==999996&&k==100000)
                    //cout<<'@'<<endl;
                printf("1");
            }
            else printf("0");
        }
        else
        {
            x=t%k;
            //if(t/k-x>=0)
            if(t>=(LL)(k+1)*x)
            {
                printf("1");
                //if(n==999996&&k==100000)
                    //cout<<'#'<<endl;
            }
            else printf("0");
        }
    }
    cout<<endl;
    return 0;
}
// davidlee1999WTK 2015/
// srO myk Orz
//ios::sync_with_stdio(false);
/*
15 2
abaabaabaabaaba
*/