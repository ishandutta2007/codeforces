#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1000005;
int n; char a[N];

int main()
{
    scanf("%d",&n);
    scanf("%s",a+1);
    int pre=-1,now=0,ans=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]=='(')
        {
            now++;
            if(now==0) ans+=(i-pre+1);
        }
        else
        {
            now--;
            if(now==-1) pre=i;
        }
    }
    if(now!=0) puts("-1");
    else printf("%d\n",ans);
    return 0;
}