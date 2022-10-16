#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define int long long
using namespace std;
int t,n,a,b;
signed main(){
//    freopen("b.in","r",stdin);
//    freopen("b.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>a>>b;
        int s1=max(a+b-n+1,1ll),s2=min(n,a+b-1);
        cout<<min(s1,n)<<' '<<max(s2,1ll)<<endl;
    }
    return 0;
}