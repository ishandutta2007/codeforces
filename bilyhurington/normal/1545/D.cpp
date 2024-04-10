/*
 * @Author: BilyHurington
 * @Date: 2021-07-14 13:26:46
 * @LastEditors: BilyHurington
 * @LastEditTime: 2021-07-14 15:04:21
 */
#include<bits/stdc++.h>
#ifdef LOCAL_TEST
#include<ctime>
#endif
using namespace std;
int n,m,val[1010][1010];
long long sum[1010],sum2[1010];
map<long long,int> mp;
int main(){
    #ifdef LOCAL_TEST
    clock_t start=clock();
    #endif
    scanf("%d %d",&m,&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&val[i][j]);
            sum[i]+=val[i][j];
            sum2[i]+=1ll*val[i][j]*val[i][j];
        }
    }
    for(int i=1;i<n;i++) mp[sum[i+1]-sum[i]]++;
    long long maxn=-1e18,maxx;
    for(auto pr:mp){
        if(pr.second>maxn){
            maxn=pr.second;
            maxx=pr.first;
        }
    }
    int wr;
    if(maxn==n-1){
        if(sum[2]-sum[1]!=maxx) wr=1;
        else wr=n;
    }else{
        for(int i=2;i<=n;i++){
            if(sum[i]-sum[i-1]!=maxx){
                wr=i;break;
            }
        }
    }
    long long k,b;
    if(wr<=2) k=sum[4]-sum[3],b=sum[3]-3*k;
    else k=sum[2]-sum[1],b=sum[1]-k;
    long long Mo=k*wr+b-sum[wr];
    long long cha;
    if(wr<=3) cha=sum2[n-2]+sum2[n]-2*sum2[n-1];
    else cha=sum2[1]+sum2[3]-2*sum2[2];
    // printf("%lld %lld %lld %lld\n",k,b,Mo,cha);
    long long wrs2;
    if(wr==1) wrs2=cha+2*sum2[2]-sum2[3];
    else if(wr==n) wrs2=cha+2*sum2[n-1]-sum2[n-2];
    else wrs2=(sum2[wr-1]+sum2[wr+1]-cha)/2;
    // printf("%lld\n",wrs2);
    printf("%d %lld",wr-1,((wrs2-sum2[wr])/Mo+Mo)/2);
    fflush(stdout);
    #ifdef LOCAL_TEST
    clock_t end=clock();cout<<endl;
    cout<<"The program costs "<<(double)(end-start)/CLOCKS_PER_SEC<<" seconds"<< endl;
    puts("");system("pause");
    #endif
    return 0;
}
//(x+cha)^2-x^2=cha*(2*x+cha)