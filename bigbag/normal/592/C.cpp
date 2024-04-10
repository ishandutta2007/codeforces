#include <bits/stdc++.h>

using namespace std;

    long long n, a, b;

    void gcd(long long d){
        long long g = n, h = d;
        while(g!=0 && h!=0)if(g>h) g%=h; else h%=g;
        long long j = max(g, h);
        cout << d/j << '/' << n/j;
    }

    long long gcd1(long long a, long long b){
        while(a!=0 && b!=0)if(a>b) a%=b; else b%=a;
        return max(a, b);
    }

int main(){
    cin >> n >> a >> b;
    long long g = gcd1(a, b);
    if(a == b){cout << "1/1"; return 0;}
    if(b>a) swap(a, b);
    long double l1=(long double)n/(long double)a*g/b;

    long long ans=0;
    long long l2 = l1;

    long double l = l2;

    ans=b*l;

    ans+=min(b-1, n-(long long)(l*a/g*b));

    gcd(ans);
    return 0;
}