// writer: w33z8kqrqk8zzzx33
#include <bits/stdc++.h>
using uint=uint32_t;
std::bitset<3<<25>sv;
signed main() {
    uint n,A,B,C,D;std::cin>>n>>A>>B>>C>>D;
    uint ans=0,t=sqrt(n);
    auto cal=[&](uint p){for(uint z=n/p,x=A*p*p*p+B*p*p+C*p+D;z;z/=p)ans+=z*x;};
    cal(2);cal(3);for(int i=5,c=0;i<=n;i++)if(i%2&&i%3){
        c++;if(sv[c])continue;cal(i);
        if(i<=t)for(int j=i*i;j<=n;j+=i)if(j%2&&j%3)sv[j/3]=1;
    }
    std::cout<<ans;
}