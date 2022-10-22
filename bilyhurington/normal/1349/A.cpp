/*
 * @Author: BilyHurington
 * @Date: 2020-02-13 19:20:46
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-05-12 20:41:54
 */
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<queue>
using namespace std;
long long n,a[100010],qz[100010],hz[100010];
long long gcd(long long x,long long y){
    if(x%y==0) return y;
    return gcd(y,x%y);
}
long long lcm(long long x,long long y){return x/gcd(x,y)*y;}
int main(){
    scanf("%d",&n);
    for(long long i=1;i<=n;i++) scanf("%d",&a[i]);
    qz[1]=a[1];
    for(long long i=2;i<=n;i++) qz[i]=gcd(qz[i-1],a[i]);
    hz[n]=a[n];
    for(long long i=n-1;i>=1;i--) hz[i]=gcd(hz[i+1],a[i]);
    long long ans=lcm(hz[2],qz[n-1]);
    for(long long i=1;i<n-1;i++) ans=lcm(ans,gcd(qz[i],hz[i+2]));
    printf("%lld",ans);
    return 0;
}