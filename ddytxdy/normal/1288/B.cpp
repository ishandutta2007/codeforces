#include<bits/stdc++.h>
using namespace std;
const int N=1e5+50;
int t,a,b;
int main(){
    // freopen("test.in","r",stdin);
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&a,&b);long long ans=0;
        for(long long i=10;;i*=10)
            if(b+1>=i)ans++;
            else break;
        cout<<a*ans<<endl;
    }
    return 0;
}