#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a,b,p,x;
LL quick(LL x,LL y,LL p){
    LL res=1;
    while (y){
        if (y&1)res = res*x%p;
        x = x*x%p;
        y/=2;
    }
    return res;
}
int main(){
    cin>>a>>b>>p>>x;
    LL ans =0;
    LL temp = a;
    for (LL i=1;i<p;i++,temp=temp*a%p){
        LL c = b*quick(temp,p-2,p)%p;
        LL k = (i-c+p)%p;
        LL minn = i+k*(p-1);
        if (minn>x)continue;
        ans += max(0LL,(x-minn)/(p*(p-1))+1);
    }
    cout<<ans<<endl;
    return 0;
}