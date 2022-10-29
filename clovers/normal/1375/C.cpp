#include<bits/stdc++.h>
using namespace std;
const int N=300005;
const int inf=(int)1e9;
int t,n,a[N],pos[N],bl[N];

int main()
{
    cin>>t;
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),bl[i]=1;
        for(int i=1;i<=n;i++)
        {
            if(a[i]>a[1]||a[i]<a[n]) bl[a[i]]=0;
        }
        int flag=0;
        for(int i=1;i<=n;i++) flag|=bl[i];
        if(!flag) puts("YES");
        else puts("NO");
    }
    return 0;
}