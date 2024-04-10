#include <iostream>
#include <cstdio>
#include <sstream>
#include <string>
#include <ctime>

using namespace std;

char a[5001][5002];

int A[5001][5001/32+1];
int B[5001][5001/32+1];

int main() {
    int n;
    cin >> n;
    int start = clock();
    for (int i = 0; i < n; i++) scanf("%s", a[i]);
    //for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) a[i][j] = '0' + (i<j);

    int less = 0;
    int more = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) if (a[i][j] == '1') {
            less += i < j;
            more += i > j;
            int ic = j / 32;
            int jc = j & 31;
            A[i][ic] |= 1<<jc;

            int jr = i / 32;
            int ir = i & 31;
            B[j][jr] |= 1<<ir;
        }
    }

    int N = n / 32 + 1;

    if (less < more) {
        for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) if (a[i][j] == '1') {
            for (int k = 0; k < N; k++) if (A[j][k]&B[i][k]) {
                cout << i+1 << ' ' << j+1 << ' ';
                for (int ki = 0; ki < 32; ki++) if (A[j][k]&B[i][k]&(1<<ki)) {
                    cout << 1+k*32+ki << endl;
                    return 0;
                }
            }
        }
    } else {
        for (int i = 0; i < n; i++) for (int j = 0; j < i; j++) if (a[i][j] == '1') {
            for (int k = 0; k < N; k++) if (A[j][k]&B[i][k]) {
                cout << i+1 << ' ' << j+1 << ' ';
                for (int ki = 0; ki < 32; ki++) if (A[j][k]&B[i][k]&(1<<ki)) {
                    cout << 1+k*32+ki << endl;
                    return 0;
                }
            }
        }
    }

    cout << -1 << endl;

    cerr << (double)(clock() - start)/CLOCKS_PER_SEC << endl;
    return 0;
}