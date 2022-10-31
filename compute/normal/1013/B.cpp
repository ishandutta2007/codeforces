#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
int arr[maxn];
int brr[maxn];
map<int,int> ext;
int main()
{
    int n,x;
    scanf("%d%d",&n,&x);
    int ans=-1;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&arr[i]);
        if(ext.count(arr[i])) ans=0;
        ext[arr[i]]++;
        brr[i]=arr[i]&x;
    }
    if(ans)
    {
        for(int i=1;i<=n;i++)
            if(ext.count(brr[i])&&brr[i]!=arr[i]) {ans=1;break;}
        ext.clear();
        if(ans!=1)
        {
            for(int i=1;i<=n;i++)
            {
                if(ext.count(brr[i])) ans=2;
                ext[brr[i]]++;
            }
        }
    }
    printf("%d\n",ans);
}