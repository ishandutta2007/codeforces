#include<bits/stdc++.h>
#ifdef LOCAL_TEST
#include<ctime>
#endif
using namespace std;
int T,n,a[100010],cnt[2];
long long solve(int t){
    long long sum=0;
    for(int i=1;i<=n;i++){
        if(!a[i]) continue;
        sum+=abs(t-i);
        if(t>n) return 1e18;
        t+=2;
    }
    if(t<=n) return 1e18;
    return sum;
}
int main(){
    #ifdef LOCAL_TEST
    clock_t start=clock();
    #endif
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);cnt[0]=cnt[1]=0;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),a[i]%=2,cnt[a[i]]++;
        if(abs(cnt[0]-cnt[1])>1){
            puts("-1");
            continue;
        }
        long long ans=1e18;
        for(int i=1;i<3;i++) ans=min(ans,solve(i));
        printf("%lld\n",ans);
    }
    #ifdef LOCAL_TEST
    clock_t end=clock();cout<<endl;
    cout<<"The program costs "<<(double)(end-start)/CLOCKS_PER_SEC<<" seconds"<< endl;
    puts("");system("pause");
    #endif
    return 0;
}