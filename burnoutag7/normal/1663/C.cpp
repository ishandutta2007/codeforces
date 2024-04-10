#include<bits/stdc++.h>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,a,sum=0;
    cin>>n;
    while(n--){
        cin>>a;
        sum+=a;
    }
    cout<<sum;

    return 0;
}