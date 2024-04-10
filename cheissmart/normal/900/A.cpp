#include <iostream>

using namespace std;

int main()
{
    int n, tmp, lct = 0, rct = 0, a[100000];
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i] >> tmp;
    for(int i=0;i<n;i++) {
        if(a[i] > 0) rct++;
        else lct++;
    }
    if(lct <= 1 || rct <= 1) cout << "Yes" << endl;
    else cout << "No" << endl;
}