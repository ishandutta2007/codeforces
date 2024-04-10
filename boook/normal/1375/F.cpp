// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
#include <bits/stdc++.h>
using namespace std;
#define PII pair<int, int>
#define F first
#define S second
#define endl "\n"
//--------------------------------------
#define int long long
#define maxn 
#define inf 0x3f3f3f3f


int32_t main(){
	//cin.tie(0), cout.sync_with_stdio(0);
    int x[3];
    cin >> x[0] >> x[1] >> x[2];

    cout << "First" << endl;
    cout << 10000000000 << endl;
    cout.flush();
    int now;
    cin >> now;
    x[now - 1] += 10000000000;
    
//    cout << "[DB]" << x[0] << " " << x[1] << " " << x[2] << endl;
    
    int y[3] = {x[0], x[1], x[2]};
    
    sort(y, y + 3);
    int a = y[2], b = y[1], c = y[0];

    cout << a + a - b - c << endl;
    cout.flush();
    cin >> now, x[now - 1] += a + a - b - c;

//    cout << "[DB]" << x[0] << " " << x[1] << " " << x[2] << endl;
    

    int z[3] = {x[0], x[1], x[2]};
    
    sort(z, z + 3);
    cout << z[1] - z[0] << endl;
    cout.flush();
    cin >> now;

    return 0;
}