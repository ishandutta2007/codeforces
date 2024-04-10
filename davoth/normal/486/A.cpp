#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#define ll long long
using namespace std;
int main(){
    ll n;
    cin>>n;
    if(n%2==0) cout<<n/2;
    else cout<<(n/2+1)*-1;
    return 0;
}