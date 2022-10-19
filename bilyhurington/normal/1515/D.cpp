/*
 * @Author: BilyHurington
 * @Date: 2021-05-02 22:36:28
 * @LastEditors: BilyHurington
 * @LastEditTime: 2021-05-02 23:28:03
 */
#include<bits/stdc++.h>
#ifdef LOCAL_TEST
#include<ctime>
#endif
using namespace std;
int T,n,L,R,num[200010];
void solve(){
    scanf("%d %d %d",&n,&L,&R);
    for(int i=1;i<=n;i++) num[i]=0;
    for(int i=1,x;i<=L;i++) scanf("%d",&x),num[x]++;
    for(int i=1,x;i<=R;i++) scanf("%d",&x),num[x]--;
    int c0=0,c1=0,s0=0,s1=0,ans=0;
    for(int i=1;i<=n;i++){
        if(num[i]<0){
            s0+=abs(num[i])/2;
            num[i]+=abs(num[i])/2*2;
            c0+=abs(num[i]);
        }else{
            s1+=abs(num[i])/2;
            num[i]-=abs(num[i])/2*2;
            c1+=num[i];
        }
    }
    // printf("%d %d %d %d\n",c0,c1,s0,s1);
    ans=s0+s1;
    if(c0<c1){
        int t=min(s0,(c1-c0)/2);
        c0+=2*t;ans-=t;
    }else{
        int t=min(s1,(c0-c1)/2);
        c1+=2*t;ans-=t;
    }
    ans+=c0+c1-min(c0,c1);
    printf("%d\n",ans);
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