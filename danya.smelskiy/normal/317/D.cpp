#include <bits/stdc++.h>
using namespace std;


const long long f[100] = {0,1,2,1,4,3,2,1,5,6,2,1,8,7,5,9,8,7,3,4,7,4,2,1,10,9,3,6,11,12};
long long n;
bool used[1000005];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    long long kol=0;
    long long ans=0;
    for (long long i=2;i<=sqrt(n);++i) if (used[i]==false) {
        long long j=i;
        int y=0;
        while (j<=n) {
            if (j<=sqrt(n)) used[j]=true;
            ++y;
            ++kol;
            j*=i;
        }
        ans^=f[y];
    }
    if ((n-kol)&1) ans^=1;
    cout<<(ans ? "Vasya" : "Petya");
}