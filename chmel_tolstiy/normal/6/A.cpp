#include <iostream>

using namespace std;

int main()
{
    int a[4];
    for (int i = 0; i < 4; i++) cin >> a[i];
    
    bool ok1 = false;
    bool ok2 = false;
    
    for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) for (int k = 0; k < 4; k++)
    {
        if (i == j || j == k || k == i) continue;
        if (a[i] + a[j] > a[k] && a[i] + a[k] > a[j] && a[k] + a[j] > a[i]) ok1 = true;
        if (a[i] + a[j] == a[k]) ok2 = true;
    }
    if (ok1) cout << "TRIANGLE" << endl;
    else
    if (ok2) cout << "SEGMENT" << endl;
    else
    cout << "IMPOSSIBLE" << endl;
    return 0;
}