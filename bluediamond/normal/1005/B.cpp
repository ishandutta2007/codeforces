#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

string a,b;
int n,m;
int cnt=0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>a>>b;
    n=a.size()-1;
    m=b.size()-1;
    while(n>=0 && m>=0 && a[n]==b[m]) {
        n--;
        m--;
    }
    cout<<n+m+2<<"\n";
    return 0;
}
/**
**/