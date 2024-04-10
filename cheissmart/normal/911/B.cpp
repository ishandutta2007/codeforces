#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, a, b, ma = 0;
    cin >> n >> a >> b;
    for(int i=1;i<n;i++) ma = max(ma, min(a/i, b/(n-i)));
    cout << ma << endl;
}