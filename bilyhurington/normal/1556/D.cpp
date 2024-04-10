#include<bits/stdc++.h>
#ifdef LOCAL_TEST
#include<ctime>
#endif
using namespace std;
int T,n,k,sum[10010];
int main(){
    #ifdef LOCAL_TEST
    clock_t start=clock();
    #endif
    // scanf("%d",&T);
    T=1;
    while(T--){
        scanf("%d %d",&n,&k);int x;
        for(int i=2;i<=n;i++){
            sum[i]=0;
            printf("or %d %d\n",1,i);
            fflush(stdout);
            scanf("%d",&x);sum[i]+=x;
            printf("and %d %d\n",1,i);
            fflush(stdout);
            scanf("%d",&x);sum[i]+=x;
        }
        int S=0;
        printf("or %d %d\n",2,3);
        fflush(stdout);
        scanf("%d",&x);S+=x;
        printf("and %d %d\n",2,3);
        fflush(stdout);
        scanf("%d",&x);S+=x;
        sum[1]=(sum[2]+sum[3]-S)/2;
        for(int i=2;i<=n;i++) sum[i]-=sum[1];
        sort(sum+1,sum+n+1);
        printf("finish %d\n",sum[k]);
        fflush(stdout);
    }
    #ifdef LOCAL_TEST
    clock_t end=clock();cout<<endl;
    cout<<"The program costs "<<(double)(end-start)/CLOCKS_PER_SEC<<" seconds"<< endl;
    puts("");system("pause");
    #endif
    return 0;
}