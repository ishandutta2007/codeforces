#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+100;
const int MOD = 1e9+9;
typedef long long LL;
char s[maxn];
LL n,a,b,k;
LL power(LL x,LL y){
    if (y==0)return 1;
    if (y&1){
        return x*power(x*x%MOD,y/2)%MOD;
    }else{
        return power(x*x%MOD,y/2);
    }
}
int main(){
    cin>>n>>a>>b>>k;
    scanf("%s",s);
    LL niA = power(a,MOD-2);
    LL niB = power(b,MOD-2);
    LL tempA = power(a,n);
    LL tempB = 1;
    LL T =0;
    for (int i=0;i<k;i++){
        T = (T+tempA*tempB%MOD*(s[i]=='+'?1:-1)+MOD)%MOD;
        tempA= tempA*niA%MOD;
        tempB = tempB*b%MOD;
    }
    LL d = (n+1)/k;
    LL fm = (1-power(1LL*b*niA%MOD,k)+MOD)%MOD;
    LL fz = (1-power(1LL*b*niA%MOD,(d)*k)+MOD)%MOD;
    if (k==n+1){
        cout<<T<<endl;
    }else
    if (a==b||fm==0){
        cout<<T*d%MOD<<endl;
    }else
        cout<<T*fz%MOD*power(fm,MOD-2)%MOD<<endl;
    return 0;
}