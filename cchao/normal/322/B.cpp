#include <iostream>
using namespace std;

int main() {
    long long a, b, c;
    cin >> a >> b >> c;

    long long ans = 0, tmp;
    tmp = max(a/3 - 1, 0LL);
    ans += tmp;
    a -= tmp*3;

    tmp = max(b/3 - 1, 0LL);
    ans += tmp;
    b -= tmp*3;

    tmp = max(c/3 - 1, 0LL);
    ans += tmp;
    c -= tmp*3;

    tmp = 0;
    for(int i = 0; i <= a; i+=3)
        for(int j = 0; j <= b; j+=3)
            for(int k = 0; k <= c; k+=3)
                tmp = max(tmp, i/3 + j/3 + k/3 + min(a-i, min(b-j, c-k)));

    cout << ans + tmp << endl;
    return 0;
}