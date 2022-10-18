#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cout<<fixed<<setprecision(20);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int q=n*n-4*n;
        if(q<0){
            cout<<"N\n";
        }else{
            double ans=n+sqrt(q);
            ans/=2;
            cout<<"Y "<<ans<<' '<<(double)(n)-ans<<"\n";
        }
    }
    return 0;
}