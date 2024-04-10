#include <iostream>
#include <algorithm>
using namespace std;

char matr[105][105];
char ans[105][105];
string s = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM1234567890";

int main() {
    int tc; cin >> tc;
    while(tc--) {
        int r, c, chi; cin >> r >> c >> chi;
        int ri = 0;
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                cin >> matr[i][j];
                ri += (matr[i][j] == 'R');
            }
        }
        int p1 = ri % chi, cur = 0, crice = 0;
        for(int i=0; i<r; i++) {
            if(i % 2) {
                for(int j=c-1; j>=0; j--) {
                    ans[i][j] = s[min(cur, chi-1)];
                    crice += (matr[i][j] == 'R');
                    if((p1 && crice == ri/chi+1) || (!p1 && crice == ri/chi)) {
                        if(p1) p1--;
                        cur++;
                        crice = 0;
                    }
                }
            } else {
                for(int j=0; j<c; j++) {
                    ans[i][j] = s[min(cur, chi-1)];;
                    crice += (matr[i][j] == 'R');
                    if((p1 && crice == ri/chi+1) || (!p1 && crice == ri/chi)) {
                        if(p1) p1--;
                        cur++;
                        crice = 0;
                    }
                }
            }
        }
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) cout << ans[i][j];
            cout << endl;
        }
    }
}