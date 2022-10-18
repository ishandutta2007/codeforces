#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    double ans=0;
    double e1=0;
    for(int i=1;i<=n;i++){
        double x;
        cin>>x;
        e1=x*(e1+1);
        ans=ans+2*e1-x;
    }
    cout<<fixed<<setprecision(12)<<ans;
    return 0;
}