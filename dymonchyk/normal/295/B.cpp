#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <ctime>
#include <cmath>
#include <set>
#include <map>

using namespace std;

int tmp[502][502],a[502][502];

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            scanf("%d",&tmp[i][j]);
    int r,p[505];
    for(int i=0;i<n;++i) {
        scanf("%d",&r); --r;
        p[n-1-i]=r;
    }
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            a[i][j]=tmp[p[i]][p[j]];
    long long ans[505]={0};
    for(int it=0;it<n;++it) {
        for(int i=0;i<it;++i)
            for(int j=0;j<it;++j)
                if (i!=j) a[i][j]=min(a[i][j],a[i][it]+a[it][j]);
        for(int k=0;k<it;++k)
            for(int j=0;j<it;++j) {
                a[it][j]=min(a[it][j],a[it][k]+a[k][j]);
                a[j][it]=min(a[j][it],a[j][k]+a[k][it]);
            }
        for(int i=0;i<it;++i)
            for(int j=0;j<it;++j)
                if (i!=j) a[i][j]=min(a[i][j],a[i][it]+a[it][j]);
        for(int k=0;k<it;++k)
            for(int j=0;j<it;++j) {
                a[it][j]=min(a[it][j],a[it][k]+a[k][j]);
                a[j][it]=min(a[j][it],a[j][k]+a[k][it]);
            }
        for(int i=0;i<=it;++i)
            for(int j=0;j<=it;++j)
                ans[it]+=a[i][j];
    }
    for(int i=0;i<n;++i) {
        if (i) printf(" ");
        printf("%I64d",ans[n-1-i]);
    }
    printf("\n");
    return 0;
}