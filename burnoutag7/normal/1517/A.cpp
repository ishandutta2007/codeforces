#include<bits/stdc++.h>
using namespace std;

long long n;
int a,t;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--){
        cin>>n;
        if(n%2050){
            cout<<"-1\n";
        }else{
            n/=2050;
            a=0;
            while(n){
                a+=n%10;
                n/=10;
            }
            cout<<a<<'\n';
        }
    }

    return 0;
}