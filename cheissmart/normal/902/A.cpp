#include <iostream>
#include <climits>

using namespace std;

int main()
{
    int n, m, maxtel = 0, maxdes = 0, minstart = INT_MAX, tel[100][2];
    bool flag = true;
    cin >> n >> m;
    for(int i=0;i<n;i++) cin >> tel[i][0] >> tel[i][1];
    for(int i=0;i<n;i++) {
        maxdes = max(maxdes, tel[i][1]);
        minstart = min(minstart, tel[i][0]);
    }
        for(int i=0;i<n-1 && tel[i][1] < m;i++) {
        maxtel = max(maxtel, tel[i][1]);
        if(maxtel < tel[i+1][0]) flag = false;
    }
    if(flag && maxdes >= m && minstart == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}