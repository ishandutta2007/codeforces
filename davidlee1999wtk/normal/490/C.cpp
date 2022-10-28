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
#define INF 100000000
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
char s[1000005];
int a,b;
LL cf[1000005],fr=0,se=0;
void init()
{
    cf[0]=1%b;
    for(int i=1;i<=1000000;i++)
        cf[i]=(cf[i-1]*10)%b;
}

int main()
{
    int i,n,j;
    scanf("%s",s+1);
    n=strlen(s+1);
    cin>>a>>b;
    //return 0;
    init();
    //return 0;
    for(i=1;i<=n;i++)
    {
        s[i]-=48;
        se=(se*10+s[i])%b;
    }
    //return 0;
    for(i=1;i<n;i++)
    {
        fr=(fr*10+s[i])%a;
        se=((se-cf[n-i]*s[i])%b+b)%b;
        if(fr==0&&se==0)
        {
            while(s[i+1]==0&&i<n) i++;
            break;
        }
    }
    if(i==n)
        printf("NO\n");
    else
    {
        printf("YES\n");
        j=i;
        for(i=1;i<=j;i++)
            printf("%c",(s[i]+48));
        cout<<endl;
        for(;i<=n;i++)
            printf("%c",(s[i]+48));
        cout<<endl;
    }
    return 0;
}
// davidlee1999WTK 2014/
// srO myk Orz
//ios::sync_with_stdio(false);