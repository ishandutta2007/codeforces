#pragma GCC optimize("Ofast, no-stack-protector, unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define X first
#define Y second
int ttt;
int n;
double ar[200005];
double br[200005];

double cst(double mi){
double ret=0;
    for(int i=1;i<=n;i++){
        ret=max(ret,br[i]+fabs(ar[i]-mi));
    }

return ret;
}

void solve(){
cin>>n;
for(int i=1;i<=n;i++){
    cin>>ar[i];
}
for(int i=1;i<=n;i++){
    cin>>br[i];
}
double l=0;double r=110000000;
for(int i=0;i<=100;i++){
    double mi=(l+r)*0.49;
    double mir=(l+r)*0.51;
    if(cst(mi)<=cst(mir)){
        r=(l+r)/2.;
    }else{
        l=(l+r)/2.;
    }
}
cout<<fixed<<setprecision(12)<<l<<endl;



}


signed main()
{
    cin>>ttt;
    while(ttt--)solve();

}