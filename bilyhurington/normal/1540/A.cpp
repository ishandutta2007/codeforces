/*
 * @Author: BilyHurington
 * @Date: 2021-06-25 23:35:11
 * @LastEditors: BilyHurington
 * @LastEditTime: 2021-06-25 23:44:00
 */
#include<bits/stdc++.h>
#ifdef LOCAL_TEST
#include<ctime>
#endif
using namespace std;
int T,n,d[100010];
void solve(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&d[i]);
    sort(d+1,d+n+1);
    long long ans=0;
    for(int i=1;i<n;i++) ans-=1ll*i*(n-i)*(d[i+1]-d[i]);
    if(d[n]>0) ans+=d[n];
    printf("%lld\n",ans);
}
int main(){
    #ifdef LOCAL_TEST
    clock_t start=clock();
    #endif
    scanf("%d",&T);
    while(T--) solve();
    #ifdef LOCAL_TEST
    clock_t end=clock();cout<<endl;
    cout<<"The program costs "<<(double)(end-start)/CLOCKS_PER_SEC<<" seconds"<< endl;
    puts("");system("pause");
    #endif
    return 0;
}