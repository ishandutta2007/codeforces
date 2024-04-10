#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
    LL n;
    cin>>n;
    n++;
    if (n==1){
        cout<<0<<endl;
        return 0;
    }
    if (n&1){
        cout<<n<<endl;
    }else{
        cout<<n/2<<endl;
    }
    return 0;
}