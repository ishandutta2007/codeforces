/*
 * @Author: BilyHurington
 * @Date: 2021-05-02 22:36:28
 * @LastEditors: BilyHurington
 * @LastEditTime: 2021-05-02 22:39:32
 */
#include<bits/stdc++.h>
#ifdef LOCAL_TEST
#include<ctime>
#endif
using namespace std;
int T,n,x,a[110];
void solve(){
    scanf("%d %d",&n,&x);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+n+1);int sum=0;
    for(int i=1;i<n;i++){
        sum+=a[i];
        if(sum==x){
            sum-=a[i];sum+=a[i+1];
            swap(a[i],a[i+1]);
        }
    }
    sum+=a[n];if(sum==x) puts("NO");
    else{
        puts("YES");
        for(int i=1;i<=n;i++) printf("%d ",a[i]);
        puts("");
    }
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