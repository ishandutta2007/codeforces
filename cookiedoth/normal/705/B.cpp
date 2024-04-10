#include <iostream>

using namespace std;

int main()
{
    int n; int i; int a; int t;
    cin >> n;
    t = 0;
    for (i=0; i<=n-1; i++) {
        cin >> a;
        t = t + (a-1);
        t = (t%2);
        if (t==0) {cout << 2 << endl;} else {cout << 1 << endl;};
    }
    return 0;
}