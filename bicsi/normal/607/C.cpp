#include <iostream>

using namespace std;

char a[5000000], b[5000000];

int main()
{
    int n;
    cin>>n;

    cin>>a+1>>b+1;

    for(int i=1; i<n; i++) {
        if(a[i] == 'N' || a[i] == 'S') a[i] ^= 'N' ^ 'S';
        else a[i] ^= 'E' ^ 'W';
    }

    for(int i=1, j=n-1; i<j; i++, j--)
        swap(a[i], a[j]);

    int64_t h1 = 0, h2 = 0, B = 319812, pw = 1;
    for(int i=1, j=n-1; i<n; i++, j--) {
        h1 = h1 * B + a[i];
        h2 = h2 + b[j] * pw;

        if(h1 == h2) { cout << "NO"; return 0; }
        pw *= B;
    }

    cout << "YES";
    return 0;
}