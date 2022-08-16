#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long
#define M 1000000007
#define MM 998244353
#define fr first
#define sc second
#define vc vector
#define pii pair<int,int>
#define msi map<string,int>
#define mii map<int,int>
#define psi pair<string,int>
#define pis pair<int,string>
#define piii pair<int,pii>
int gcd(int a,int b){
    if(b==0)return a;
    return gcd(b,a%b);
}


void solve(){
    int a[3];int z=0,x=0;
    cin>>a[0]>>a[1]>>a[2];
    sort(a,a+3);
    z+=a[0];x=z;
    a[1]-=a[0];a[2]-=a[0];
    int u=a[1]/3,v=a[2]/3,w=v-u,y=min(w,x);
    v-=y;x-=y;a[2]-=3*y;z+=y;

    int q=min(u,x);
    u-=q/2+q%2;v-=q/2;a[1]-=3*(q/2+q%2);a[2]-=3*(q/2);z+=q;

    w=a[2]-a[1];y=min(w,a[1]);
    a[1]-=y;a[2]-=2*y;z+=y;
    z+=2*(a[1]/3);
    a[1]%=3;a[2]%=3;
    if(a[1]==2&&a[2]==2)z++;
    cout<<z;
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