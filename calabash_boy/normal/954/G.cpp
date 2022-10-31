#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 5e5+100;
int n,rr;
LL k;
LL a[maxn];
LL x[maxn];
LL l,r;
void input(){
    l = 0x3f3f3f3f3f3f3f3fLL;
    LL sum = 0;
    scanf("%d%d%I64d",&n,&rr,&k);
    for (int i=0;i<n;i++){
        scanf("%I64d",a+i);
        l = min(l,a[i]);
        sum+=a[i];
    }
    r = k+sum;
}
bool check(LL xx){
    memset(x,0,sizeof x);
    int l=0,r=min(rr,n-1);
    int lnow=0,rnow=0;
    LL now=0;
    LL temp =a[0];
    for (int i=0;i<n;i++,r = min(n-1,i+rr),l = max(0,i-rr)){
        while (rnow<r){
            temp+=x[++rnow];
            temp+=a[rnow];
        }
        while (lnow<l){
            temp-=a[lnow];
            temp-=x[lnow++];
        }
        LL t = xx-temp;
//        printf("t:%d\n",t);
        if (t<=0)continue;
        x[r]+=t;
        now+=t;
        temp+=t;
//        printf("%d %d\n",i,temp);
        if (now>k)return false;
    }
    return true;
}
void solve(){
    while (r-l>1){
        LL mid = l+r >>1;
 //       cout<<mid<<endl;
        if (check(mid)){
            l = mid;
        }else{
            r = mid;
        }
    }
    if (check(r)){
        cout<<r<<endl;
    }else{
        cout<<l<<endl;
    }
}
int main(){
   input();
   solve();
   return 0;
}