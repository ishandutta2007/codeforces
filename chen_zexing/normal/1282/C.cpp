#include <stdio.h>
#include<iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <map>
#include <stack>
using namespace std;
long long f[200005],c[200005],id[200005];
bool cmp(int a,int b){
    return c[a]<c[b];
}
int main() {
    int T;
    cin>>T;
    while(T--){
        long long n,t,a,b,ra=0,rb=0;
        cin>>n>>t>>a>>b;
        for(int i=1;i<=n;i++){
            scanf("%lld",&f[i]);
            if(f[i]==0) ra++;
            else rb++;
        }
        for(int i=1;i<=n;i++) scanf("%lld",&c[i]),id[i]=i;
        sort(id+1,id+n+1,cmp);
        long long ans=0,now=0;
        c[n+1]=t+1;
        id[n+1]=n+1;
        for(int i=0;i<=n;i++) {
            if (i) {
                if (!f[id[i]]) now+=a,ra--;
                else now+=b,rb--;
            }
            if (now >= c[id[i + 1]]) continue;
            ans=max(ans,i+min((c[id[i+1]]-now-1)/a,ra));
        }
        cout<<ans<<endl;
    }
    return 0;
}