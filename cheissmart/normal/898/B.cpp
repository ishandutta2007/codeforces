#include <iostream>

using namespace std;

int main()
{
    int n, a, b;
    bool flag = true;
    cin >> n >> a >> b;
    for(int x=0;x<=n/a;x++){
        if((n - a * x) % b) continue;
        int y = (n - a * x) / b;
        flag = false;
        cout << "YES" << endl;
        cout << x << " " << y << endl;
        break;
    }
    if(flag) cout << "NO" << endl;
}