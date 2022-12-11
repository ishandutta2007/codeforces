#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=2e5+50;
const LL inf=1e12;
int n,ans;LL a[N];
void check(LL p){
    LL now=0;
    for(int i=1;i<=n;i++){
        LL dat=a[i]%p;
        now+=a[i]<p?p-a[i]:min(dat,p-dat);
        if(now>=ans)return;
    }
    ans=now;
}
void solve(LL x){
    for(int i=2;1ll*i*i<=x;i++){
        if(x%i)continue;
        check(i);while(x%i==0)x/=i;
    }
    if(x!=1)check(x);
}
int main(){
    scanf("%d",&n);int st=clock();ans=n;
    srand(time(0)+(unsigned long long)new int);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    while(clock()-st<2000){
        int p=rand()*rand()%n+1;
        solve(a[p]);
        if(a[p]>1)solve(a[p]-1);
        solve(a[p]+1);
    }
    cout<<ans;
    return 0;
}