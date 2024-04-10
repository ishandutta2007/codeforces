#include <bits/stdc++.h>
using namespace std;

long long n;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;

    long long s1=0,s2=0;
    for (int i=1;i<=n;++i) {
        long long x;
        cin>>x;
        if (x>=0) s1+=x;
        else s2+=x;
    }
    cout<<s1-s2;

}