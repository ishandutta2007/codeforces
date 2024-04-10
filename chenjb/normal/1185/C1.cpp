#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <cmath>
#define rep(i,n) for(int i=1;i<=n;++i)
#define mp make_pair
#define pb push_back
using namespace std;
int n,m;
int a[210000];
int cnt[110];
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        if (i>1)putchar(' ');
        sum+=a[i];
        int now=sum;
        int ans=0;
        for(int j=100;j>=1;j--)
        {
            if (now-cnt[j]*j>m){ now-=cnt[j]*j; ans+=cnt[j]; continue; }
            int l=0; int r=cnt[j];
            while (l<r)
            {
                int mid=(l+r)/2;
                if (now-mid*j<=m)r=mid;
                else l=mid+1;
            }
            ans+=l;
            break;
        }
        printf("%d",ans);
        cnt[a[i]]++;
    }
    puts("");
    return 0;
}