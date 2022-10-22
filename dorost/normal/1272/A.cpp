#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
   ll t, a[3];
   cin >> t;
   while(t--){
        for (int i = 0; i < 3; i++){
            cin >> a[i];
        }
        sort (a, a + 3);
        if(a[0] == a[1] == a[2]){
            cout << 0;
        }else if(a[0] == a[1]){
            int m = (a[2] - a[1] - 2) * 2;
            if (m < 0){
                cout << 0;
            }else{
                 cout << (a[2] - a[1] - 2) * 2;
            }
        }else if(a[1] == a[2]){
            int m = (a[1] - a[0] - 2) * 2;
            if (m < 0){
                cout << 0;
            }else{
                cout << (a[1] - a[0] - 2) * 2;
            }
        }else{
            a[0] ++;
            a[2] --;
            cout << min (a[2] - a[0] + a[1] - a[0] + a[2] - a[1],
            a[2] - a[0] + a[1] + 1 - a[0] + a[2] - a[1] + 1);
        }
        cout << endl;
   }
}