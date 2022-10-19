#include<bits/stdc++.h>
#ifdef LOCAL_TEST
#include<ctime>
#endif
using namespace std;
int n1,n2,nxt[100010],cnt[100010];
char A[100010],B[100010];
int main(){
    #ifdef LOCAL_TEST
    clock_t start=clock();
    #endif
    scanf("%s %s",A+1,B+1);
    n1=strlen(A+1);n2=strlen(B+1);
    for(int i=2,j=0;i<=n2;i++){
        while(j>0&&B[j+1]!=B[i]) j=nxt[j];
        if(B[j+1]==B[i]) j++;
        nxt[i]=j;
    } 
    for(int i=2,j=0;i<=n1;i++){
        while(j>0&&B[j+1]!=A[i]) j=nxt[j];
        if(B[j+1]==A[i]) j++;
        cnt[j]++;
    }
    for(int i=n2;i>=1;i--) cnt[nxt[i]]+=cnt[i];
    long long ans=1ll*n1*n2;
    for(int i=1;i<=n2;i++) if(nxt[i]>0&&i-nxt[i]>0) ans-=cnt[i-nxt[i]];
    printf("%lld",ans);
    #ifdef LOCAL_TEST
    clock_t end=clock();cout<<endl;
    cout<<"The program costs "<<(double)(end-start)/CLOCKS_PER_SEC<<" seconds"<< endl;
    puts("");system("pause");
    #endif
    return 0;
}