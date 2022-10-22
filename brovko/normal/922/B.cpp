#include <bits/stdc++.h>
//#define int long long
#define y1 dwihweoighweoi
#define ld long double

using namespace std;

int n, k;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int a=1;a<=n;a++)
        for(int b=1;b<=n;b++)
    {
        int c=a^b;
        int Max=max(a, max(b, c));
        if(a+b+c-Max>Max && c>0 && c<=n)
            k++;
    }
    cout << k/6;
}