#include <iostream>
using namespace std;

int a[4];

int main() {
    cin >> a[0] >> a[1] >> a[2] >> a[3];
    int t = a[0]+a[1]+a[2]+a[3];
    for(int b=0;b<=1;b++) {
        for(int c=0;c<=1;c++) {
            for(int d=0;d<=1;d++) {
                for(int e=0;e<=1;e++) {
                    int v = 0;
                    if(b) v += a[0];
                    if(c) v += a[1];
                    if(d) v += a[2];
                    if(e) v += a[3];
                    if(v == t-v) {
                        cout << "YES" << endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout << "NO" << endl;
}