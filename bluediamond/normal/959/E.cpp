#include <iostream>
using namespace std;
long long f(long long x){
    return x&(-x);
    /// sau (x^(x-1))&x;
}
long long n,ans;
int main(){
    cin>>n;
    n--;
    for(long long i=0;i<=60;i++){
        ans+=((n+(1LL<<i))/(1LL<<(i+1)))*(1LL<<i);
    }
    cout<<ans;
    return 0;
}
/**
i -> incepe cu (1<<i) si are perioada (1<<(i+1))
4 - 12 - 20 - 28
**/