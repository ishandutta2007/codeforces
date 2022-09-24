#include<cstdio>
#include<algorithm>
#include<iostream>
#pragma GCC optimize("Ofast" , "no-stack-protector") 
#pragma GCC target("sse4.1" , "sse4.2" , "sse3" , "sse2" , "sse4" , "popcnt")
#pragma ("unroll loops")
using namespace std;//
int n, m, q, w[101000];
int main() {
    int i, j;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    for (i = 1; i <= n; i++) cin>> w[i];
    while (q--)
    {
        int ck, a, b, c, r =0 ;
        cin >> ck >> a >> b >> c;
        if (ck == 1)
        {
            for (i = a; i <= b; i++)if (w[i] > c)w[i] -= c;
        }
        else
        {
            for (i = a; i <= b; i++)if (w[i] == c)r++;
            cout << r << "\n";
        }
    }
    return 0;
}