#include <bits/stdc++.h>
using namespace std;
long long n;
int main(){
    cin>>n;
    if (n<=2) cout<<"1";
    else if (n%2==0) cout<<"2";
    else {
         bool t=false;
        for (int i=2;i<=sqrt(n);++i){
            if (n%i==0){
                t=true;
                break;
            }
        }
        if (t==false) cout<<"1";
        else {
            n-=2;
            for (int i=2;i<=sqrt(n);++i)
            if (n%i==0){
                cout<<3;
                return 0;
            }
            cout<<2;
        }
    }
}