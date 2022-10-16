#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, a[200000], ct = 0;
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    sort(a, a+n);
    for(int i=0, j=n-1;i < j;i++, j--) {
        if(a[j] == 1) {
            ct += (j - i + 1)/3;
            break;
        } else {
            if(a[i] == 1) ct++;
            else break;
        }
    }
    cout << ct << endl;
}