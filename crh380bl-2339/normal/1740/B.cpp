#include<bits/stdc++.h>
using namespace std;
pair<int,int>a[200005];
void work(){
    int n,i;
    long long ans = 0;
    scanf("%d",&n);
    for(i=1;i<=n;++i){
        scanf("%d%d",&a[i].first,&a[i].second);
        ans+=2LL*(a[i].first+a[i].second);
        if(a[i].first<a[i].second)swap(a[i].first,a[i].second);
    }
    sort(a+1,a+1+n);
    for(i=1;i<n;++i){
        ans -= 2LL*min(a[i].first, a[i+1].first);
    }
    printf("%lld\n",ans);
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--)work();
    return 0;
}