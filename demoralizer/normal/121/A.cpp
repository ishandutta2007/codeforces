#include <bits/stdc++.h>
using namespace std;
#define pb                push_back
#define all(x)            (x).begin(),(x).end()
#define int               long long
#define M                 1000000007
#define MM                998244353
#define fr                first
#define sc                second
#define vc                vector
#define pii               pair<int,int>
#define msi               map<string,int>
#define mii               map<int,int>
#define psi               pair<string,int>
#define pis               pair<int,string>
int gcd(int a,int b){
    if(b==0)return a;
    return gcd(b,a%b);
}
int pw(int a,int b,int p){
    if(b==0)return 1;
    int t=pw(a,b/2,p);
    if(b%2)return (((a*t)%p)*t)%p;
    else return ((t*t)%p);
}

void solve(){
    int l,r;
    cin>>l>>r;int pre=l,ans=0;
    for (int i = 2; i < 1<<11; ++i)
    {
        int z=i,n=0;
        while(z>0){
            int d=z%2;
            if(!d)n=10*n+4;
            else n=10*n+7;
            z/=2;
        }
        int m=n/10;
        n=0;
        while(m>0){
            int d=m%10;
            n=10*n+d;
            m/=10;
        }
        //cout<<n<<" "<<i<<"\n";
        if(n<l)continue;
        if(n>=r){
            ans+=(r-pre+1)*n;
            break;
        }
        ans+=(n-pre+1)*n;
        pre=n+1;
    }
    cout<<ans;
}
signed main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t=1;
    //cin>>t;
    while(t--) solve();
    return 0;
}