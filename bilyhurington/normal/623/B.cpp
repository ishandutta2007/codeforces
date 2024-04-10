/*
 * @Author: BilyHurington
 * @Date: 2021-06-30 14:16:10
 * @LastEditors: BilyHurington
 * @LastEditTime: 2021-06-30 14:46:12
 */
#include<bits/stdc++.h>
#ifdef LOCAL_TEST
#include<ctime>
#endif
using namespace std;
int n,A,B,a[1000010];
long long ans=1e18;
long long val[1000010];
void solve(int d){
    // printf("SOLVE %d\n",d);
    int l=n+1,r=0;
    for(int i=1;i<=n;i++){
        if(a[i]%d==0) val[i]=0;
        else if((a[i]+1)%d==0||(a[i]-1)%d==0) val[i]=B;
        else r=max(r,i),l=min(l,i);
    }
    // for(int i=1;i<=n;i++) printf("%lld ",val[i]);puts("");
    // printf("%d %d\n",l,r);
    if(l>r){
        long long sum=0;
        for(int i=1;i<=n;i++){
            sum+=val[i];
            val[i]=A-val[i];
        }
        long long minn=0,minx=0;
        for(int i=1;i<=n;i++){
            minx=min(val[i],minx+val[i]);
            minn=min(minn,minx);
        }
        ans=min(ans,sum+minn);
        // printf("%lld %lld\n",sum,minn);
    }else{
        long long sum=1ll*A*(r-l+1);
        for(int i=1;i<=n;i++){
            if(i>=l&&i<=r) continue;
            sum+=val[i];
            val[i]=A-val[i];
        }
        long long min_pre=0,min_suf=0;
        for(int i=1;i<=n;i++) val[i]+=val[i-1];
        for(int i=1;i<l;i++) min_pre=min(min_pre,val[l-1]-val[i-1]);
        for(int i=r+1;i<=n;i++) min_suf=min(min_suf,val[i]-val[r]);
        ans=min(ans,sum+min_pre+min_suf);
        // printf("%lld %lld %lld\n",sum,min_pre,min_suf);
    }
}
int num[6];
vector<int> di;
void divide(int x){
    for(int i=2;i*i<=x;i++){
        if(x%i>0) continue;
        di.push_back(i);
        while(x%i==0) x/=i;
    }
    if(x>1) di.push_back(x);
}
int main(){
    #ifdef LOCAL_TEST
    clock_t start=clock();
    #endif
    scanf("%d %d %d",&n,&A,&B);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    num[0]=a[1]-1;num[1]=a[1];num[2]=a[1]+1;
    num[3]=a[n]-1;num[4]=a[n];num[5]=a[n]+1;
    for(int i=0;i<6;i++) divide(num[i]);
    sort(di.begin(),di.end());
    di.erase(unique(di.begin(),di.end()),di.end());
    for(auto x:di) solve(x);
    printf("%lld",ans);
    #ifdef LOCAL_TEST
    clock_t end=clock();cout<<endl;
    cout<<"The program costs "<<(double)(end-start)/CLOCKS_PER_SEC<<" seconds"<< endl;
    puts("");system("pause");
    #endif
    return 0;
}