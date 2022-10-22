#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew
#define y0 wepfjwewpjfef

using namespace std;

ld a, b, c, A[15];
int ans, Max;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b >> c;

    Max = 1;

    A[1] = log(a) * powl(b, c);
    A[2] = log(a) * powl(c, b);
    A[3] = log(a) * b * c;
    A[4] = log(a) * c * b;
    A[5] = log(b) * powl(a, c);
    A[6] = log(b) * powl(c, a);
    A[7] = log(b) * a * c;
    A[8] = log(b) * c * a;
    A[9] = log(c) * powl(a, b);
    A[10] = log(c) * powl(b, a);
    A[11] = log(c) * a * b;
    A[12] = log(c) * b * a;

    for(int i = 1; i <= 12; i++)
    {
        if(A[i] > A[Max] + 1e-9)
            Max = i;
    }

    if(Max == 1)
        cout << "x^y^z";

    else if(Max == 2)
        cout << "x^z^y";

    else if(Max == 3)
        cout << "(x^y)^z";

    else if(Max == 4)
        cout << "(x^z)^y";

    else if(Max == 5)
        cout << "y^x^z";

    else if(Max == 6)
        cout << "y^z^x";

    else if(Max == 7)
        cout << "(y^x)^z";

    else if(Max == 8)
        cout << "(y^z)^x";

    else if(Max == 9)
        cout << "z^x^y";

    else if(Max == 10)
        cout << "z^y^x";

    else if(Max == 11)
        cout << "(z^x)^y";

    else if(Max == 12)
        cout << "(z^y)^x";
}