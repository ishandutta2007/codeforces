#include<bits/stdc++.h>
#ifdef LOCAL_TEST
#include<ctime>
#endif
#define int long long
using namespace std;
int n,c[1010],cnt[1010];
signed main(){
    #ifdef LOCAL_TEST
    clock_t start=clock();
    #endif
    scanf("%lld",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&c[i]);
    unsigned long long ans=0;
    for(int i=1;i<=n;i+=2){
        long long t=0,l=0;
        for(int j=i+1;j<=n;j+=2){
            if(t>c[i]) break;
            if(t+l<=c[j]&&c[i]+l>=0){
                // printf("%lld %lld %lld %lld\n",i,j,l,t);
                ans+=min(c[i],c[j]-l)-max(t,-l);
                if(j-i!=1) ans++;
            }
            t=max(t,-l+c[j]);
            l+=-c[j]+c[j+1];
        }
    }
    printf("%lld\n",ans);
    #ifdef LOCAL_TEST
    clock_t end=clock();cout<<endl;
    cout<<"The program costs "<<(double)(end-start)/CLOCKS_PER_SEC<<" seconds"<< endl;
    puts("");system("pause");
    #endif
    return 0;
}