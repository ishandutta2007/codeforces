/*
 * @Author: BilyHurington
 * @Date: 2020-09-14 12:59:19
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-09-14 13:41:18
 */
#include<bits/stdc++.h>
using namespace std;
int N,f[1<<20];long long A[21];
void get_set(long long *a,int n,long long *sum){
    // printf("GET_SET %d\n",n);
    // for(int i=0;i<n;i++) printf("%lld ",a[i]);printf("\n");
    static long long tmp[1<<10];sum[0]=0;
    for(int i=0;i<n;i++){
        memcpy(tmp,sum,sizeof(long long)*(1<<i));
        int l1,l2,tot;l1=l2=tot=0;
        while(l1<(1<<i)&&l2<(1<<i)){
            long long t1=tmp[l1]-a[i],t2=tmp[l2]+a[i];
            if(t1<t2) sum[tot++]=t1,l1++;
            else sum[tot++]=t2,l2++;
        }
        while(l1<(1<<i)) sum[tot++]=tmp[l1++]-a[i];
        while(l2<(1<<i)) sum[tot++]=tmp[l2++]+a[i];
    }
    // for(int i=0;i<(1<<n);i++) printf("%lld ",sum[i]);printf("\n");
}
bool check(int sta){
    // printf("%d\n",sta);
    static long long b[21];int n=0;
    long long sum=0;
    for(int i=0;i<N;i++) if((sta>>i)&1) b[n++]=A[i],sum+=A[i];
    if((sum-(n-1))&1) return 0;
    // for(int i=0;i<n;i++) printf("%lld ",b[i]);printf("\n");
    static long long s1[1<<10],s2[1<<10];
    int n1=(n>>1),n2=n-n1,tmp=1;
    if(abs(sum)<n) tmp+=2;
    get_set(b,n>>1,s1);get_set(b+(n>>1),n-(n>>1),s2);
    for(int i=(1<<n1)-1,j=0;i>=0;i--){
        while(j<(1<<n2)&&s1[i]+s2[j]<=-n) j++;
        for(int k=j;k<(1<<n2)&&tmp&&abs(s1[i]+s2[k])<n;k++) tmp--;
    }
    if(!tmp) return 1;
    return 0;
}
int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%lld",&A[i]);
        if(!A[i]) N--,i--;
    }
    for(int i=1;i<(1<<N);i++){
        if(f[i]||!check(i)) continue;
        f[i]=1;
        for(int k=((1<<N)-1)^i,j=k;j;j=(j-1)&k) f[i^j]=max(f[i^j],f[j]+1);
    }
    printf("%d",N-f[(1<<N)-1]);
    return 0;
}