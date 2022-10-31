#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB(x) push_back(x)
#define debug(x) cerr<<"[debug] "<<#x<<":"<<x<<endl;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
#define NO do{puts("No");exit(0);}while(0);
typedef long long ll;
const int maxn = 2e5+100;
const ll inf = 0x3f3f3f3f3f3f3f3fLL;
ll a[maxn],l[maxn],x[maxn],b[maxn],lef[maxn],rig[maxn];
void input(ll n){
    for(int i=1;i<=n;++i){
        scanf("%lld",a+i);
    }
    for (int i=1;i<=n;i++){
        scanf("%lld",x+i);
        if(x[i]<i) {
            NO;
        }
    }
    for(int i=1;i<=n;++i) {
        if(x[i]>i) {
            l[i]++,l[x[i]]--;
        }
    }
}
void output_res(ll n){
    puts("Yes");
    for(int i=1;i<=n;++i){
        printf("%lld ",b[i]);
    }
    printf("\n");
}
void work(ll n,ll t){
    for(int i=1;i<=n;++i) {
        l[i]+=l[i-1];
        if(l[i]){
            lef[i]=a[i+1]+t;
        } else{
            lef[i]=a[i]+t;
        }
    }
    memset(rig,inf,sizeof rig);
    for(int i=1;i<=n;++i){
        if(x[i]>i&&x[i]!=n){
            rig[x[i]]=a[x[i]+1]+t-1;
        }
    }
    ll L=-1;
    for(int i=1;i<=n;++i) {
        L=max(L,lef[i]);
        L=max(L,b[i-1]+1);
        if(L>rig[i]){
            NO
        }
        b[i]=L;
    }
    output_res(n);
}
int main() {
    ll n;ll t;
    scanf("%lld %lld",&n,&t);
    input(n);
    work(n,t);
    return 0;
}