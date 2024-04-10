#include <cstdio>
#include <algorithm>
using namespace std;
int a[5005];
int dfs(int l,int r,int d)
{
    if(l>r)
        return 0;
    if(l==r)
        return a[l]!=d;
    int p=l;
    for(int i=l;i<=r;i++)
        if(a[i]<a[p])
            p=i;
    return min(r-l+1,dfs(l,p-1,a[p])+dfs(p+1,r,a[p])+a[p]-d);
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("%d\n",dfs(0,n-1,0));
    return 0;
}