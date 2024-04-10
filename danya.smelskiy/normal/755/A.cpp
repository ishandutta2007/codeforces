#include <bits/stdc++.h>
using namespace std;

long long n;
bool t;

int main(){
    cin>>n;
    for (int i=1;;++i){
        long long x=n*i+1;
        bool t=false;
        for (int j=2;j<=sqrt(x);++j){
            if (x%j==0) {
                t=true;
                break;
            }
        }
        if (t==true){
            cout<<i;
            return 0;
        }
    }
}