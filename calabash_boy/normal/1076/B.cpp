#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+100;
int prime[maxn],tot;
bool used[maxn];
void init(){
    for (int i=2;i<maxn;i++){
        if (!used[i])prime[tot++] = i;
        for (int j=0;j<tot;j++){
            long long temp = 1ll * i * prime[j];
            if (temp > maxn)break;
            used[temp] = 1;
            if (i%prime[j])break;
        }
    }
}
int main(){
    long long n;
    cin>>n;
    init();
    for (int i=0;i<tot;i++){
        if (n%prime[i] == 0){
            cout<<1+(n-prime[i])/2<<endl;
            return 0;
        }
        long long temp = prime[i] * prime[i];
        if (temp > n)break;
    }
    cout<<1<<endl;
    return 0;
}