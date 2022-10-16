#include <iostream>

using namespace std;

int main()
{
    int n, x;
    cin >> n;
    while(n--){
        bool flag = true;
        cin >> x;
        for(int b=0;b<=x/7;b++) {
            if((x - b * 7) % 3) continue;
            int a = (x - b * 7) / 3;
            flag = false;
            cout << "YES" << endl;
            break;
        }
        if(flag) cout << "NO" << endl;
    }
}