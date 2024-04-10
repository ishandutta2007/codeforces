#include <bits/stdc++.h>
using namespace std;
long long n,k,x,y,ans=100000000000000;
int main(){
    cin>>n;
    for (int i=1;i<=sqrt(n);++i){
        if (n%i==0){
            k=abs(i-n/i);
            if (k<ans){
                ans=k;
                x=i;
                y=n/i;
            }
        }
    }
    cout<<x<<" "<<y;
}