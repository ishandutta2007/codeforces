#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=100005;
const long long inf=(1ll<<56);
int n;
int a[maxn];

int main(){
    ios::sync_with_stdio(0);
    int t;cin>>t;
    while(t--){
        cin>>n;
        cout<<3<<'\n';
        long long sum=0,x=inf;
        long long os=0,ox=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            sum+=a[i];
            x^=a[i];
            os+=a[i];ox^=a[i];
        }
        assert((sum+x)%2==0);
        long long g=inf-(sum+x)/2;
        os+=x+g+g;ox^=x^g^g;
        assert(os==(ox<<1));
        cout<<x<<' '<<g<<' '<<g<<'\n';
    }
    return 0;
}