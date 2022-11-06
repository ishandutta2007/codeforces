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
char a[100010];
long long hv[1000];
int main()
{
    int len,n1;
    cin>>len;
    scanf("%s",a);
    long long ans=0;
    for(n1=1;n1<=len;n1++)
    {
        hv[a[n1-1]]++;
        ans=max(ans,hv[a[n1-1]]);
    }
    int now=-1,p=1;
    for(n1=1;n1<=100;n1++)
        if(hv[n1]>now)
        {
            now=hv[n1];
            p=1;
        }
        else
            if(hv[n1]==now)
                p++;
    ans=1;
    for(n1=1;n1<=len;n1++)
        ans=ans*p%(inf+7);
    cout<<ans;
}