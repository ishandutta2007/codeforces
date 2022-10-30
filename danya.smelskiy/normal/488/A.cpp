#include <bits/stdc++.h>
using namespace std;
long long n,ans;
int main(){
    cin>>n;
    while (true){
        ++n;
        ++ans;
        long long y=n;
        while (y!=0){
            if (abs(y%10)==8) {
                    cout<<ans;
                return 0;
            }
            y/=10;
        }
    }
}