#include <bits/stdc++.h>
using namespace std;
long long n;
int main(){
    cin>>n;
    --n;
    if (n==-1){
        cout<<"1";
        return 0;
    }
    long long m=n;
    long long x=1;
    long long y=2;
    while (m>0){
        if (m%2==0){
            y=(y*y)%1000000007;
            m/=2;
        } else {
            --m;
            x=(x*y)%1000000007;
        }
    }
    y=(x*2)%1000000007;
    y=(x)*(y+1)%1000000007;
    cout<<y;
}