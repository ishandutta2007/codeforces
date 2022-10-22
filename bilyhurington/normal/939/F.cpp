/*
 * @Author: BilyHurington
 * @Date: 2021-07-06 07:49:00
 * @LastEditors: BilyHurington
 * @LastEditTime: 2021-07-06 08:43:53
 */
#include<bits/stdc++.h>
#ifdef LOCAL_TEST
#include<ctime>
#endif
using namespace std;
int n,k,N,f[200010],g[200010],q[200010];
int main(){
    #ifdef LOCAL_TEST
    clock_t start=clock();
    #endif
    scanf("%d %d",&n,&k);N=2*n;
    f[0]=0;for(int i=1;i<=N;i++) f[i]=2e9;
    for(int i=1,L,R;i<=k;i++){
        scanf("%d %d",&L,&R);
        memcpy(g,f,sizeof(f));
        int lt=1,rt=0;
        for(int j=0;j<=N+R-L;j++){
            if(j<=N){
                while(rt>=lt&&g[q[rt]]>=g[j]) rt--;
                q[++rt]=j;
            }
            if(j<=N) f[j]=min(f[j],g[q[lt]]+2);
            if(j<=R) f[R-j]=min(f[R-j],g[q[lt]]+1);
            if(j-q[lt]>=R-L) lt++;
        }
    }
    if(f[n]>1e9) puts("Hungry");
    else printf("Full\n%d",f[n]);
    #ifdef LOCAL_TEST
    clock_t end=clock();cout<<endl;
    cout<<"The program costs "<<(double)(end-start)/CLOCKS_PER_SEC<<" seconds"<< endl;
    puts("");system("pause");
    #endif
    return 0;
}