#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
int n,m;
string s[1100000];
int a[1100000];
bool cmp(int x,int y)
{
    for(int i=0;i<m;i++)
    {
        if (s[x][i]==s[y][i])continue;
        if (i%2==0)return s[x][i]<s[y][i];
        if (i%2==1)return s[x][i]>s[y][i];
    }
    return 0;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        static char ss[1100000];
        scanf("%s",ss+1);
        s[i].clear();
        for(int j=1;j<=m;j++)s[i].pb(ss[j]);
    }
    //for(int i=1;i<=n;i++)cout<<s[i]<<endl;
    for(int i=1;i<=n;i++)a[i]=i;
    //for(int i=1;i<=n;i++)
   // for(int j=i+1;j<=n;j++)
   // if (!cmp(a[i],a[j]))swap(a[i],a[j]);
    sort(a+1,a+n+1,cmp); //reverse(a+1,a+n+1);
    for(int i=1;i<=n;i++)printf("%d%c",a[i],i==n?'\n':' ');
    return 0;
}