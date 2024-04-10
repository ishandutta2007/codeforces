#include<bits/stdc++.h>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;cin>>n;
    for(int i=2;;i++)if(n%i==0){cout<<i<<n/i<<endl;break;}

    return 0;
}