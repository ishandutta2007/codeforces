#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;
struct node
{
    long long a,b;
    friend bool operator <(node x,node y)
    {
        return x.b*y.a<y.b*x.a;
    }
}a[110000];
int n;
char s[110000];
int main()
{
    cin>>n;
    long long ans=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%s",s+1);
        a[i].a=0; a[i].b=0;
        int len=strlen(s+1);
        for(int j=1;j<=len;j++)
            if (s[j]=='s')a[i].a++;
            else a[i].b++,ans+=a[i].a;
    }
    sort(a+1,a+n+1);
    long long x=0;
    for(int i=1;i<=n;i++)
    {
        ans+=a[i].b*x;
        x+=a[i].a; 
    }
    cout<<ans<<endl;
}