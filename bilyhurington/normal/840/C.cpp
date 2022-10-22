/*
 * @Author: BilyHurington
 * @Date: 2020-07-05 00:37:47
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-07-05 01:01:44
 */ 
#include<bits/stdc++.h>
using namespace std;
int n,a[310];const int mod=1e9+7;
void add(int &a,int b){a+=b;a-=a>=mod?mod:0;}
void mius(int &a,int b){a-=b;a+=a<0?mod:0;}
vector<int> poly_mul(vector<int> &A,vector<int> &B){
    vector<int> ans;ans.resize(A.size()+B.size()-1);
    for(int i=0;i<A.size();i++){
        for(int j=0;j<B.size();j++) add(ans[i+j],1ll*A[i]*B[j]%mod);
    }
    return ans;
}
long long fast_pow(long long x,long long k){
    long long ans=1;
    for(;k;k>>=1,x=x*x%mod) if(k&1) ans=ans*x%mod;
    return ans;
}
map<int,int> mp;long long fac[310],fac_inv[310];
int main(){
    scanf("%d",&n);
    fac[0]=1;for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
    fac_inv[n]=fast_pow(fac[n],mod-2);for(int i=n;i>=1;i--) fac_inv[i-1]=fac_inv[i]*i%mod;
    // printf("OK\n");
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        for(int j=2;j*j<=a[i];j++){
            while(a[i]%(j*j)==0) a[i]/=j*j;
        }
        // printf("%d\n",a[i]);
        mp[a[i]]++;
    }
    vector<int> Ans;Ans.push_back(1);
    for(map<int,int>::iterator it=mp.begin();it!=mp.end();++it){
        vector<int> poly;poly.resize(it->second);
        for(int j=0;j<it->second;j++) poly[j]=fac[it->second]*fac[it->second-1]%mod*fac_inv[j]%mod*fac_inv[it->second-1-j]%mod*fac_inv[it->second-j]%mod;
        Ans=poly_mul(Ans,poly);
    }
    int ans=0;
    for(int i=0;i<Ans.size();i++){
        if(i&1) mius(ans,1ll*Ans[i]*fac[n-i]%mod);
        else add(ans,1ll*Ans[i]*fac[n-i]%mod);
    }
    printf("%d",ans);
    return 0;
}