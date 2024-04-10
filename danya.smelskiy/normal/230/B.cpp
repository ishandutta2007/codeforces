#include <bits/stdc++.h>
using namespace std;
long long n,x;
int main(){
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>x;
        if (round(sqrt(x))*round(sqrt(x))==x && x!=1) {
            int y=sqrt(x);
            bool t=false;
            for (int i=2;i<=sqrt(y);++i)
            if (y%i==0) { t=true; break;}
            if (t==false) cout<<"YES";
            else cout<<"NO";
        }
        else cout<<"NO";
        cout<<'\n';
    }
}