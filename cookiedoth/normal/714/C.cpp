#include <iostream>
#include <string>
//#include <fstream>

using namespace std;

const int c20 = 550000;
const int dg = 18;

long long n, pow2[20], ans[c20], a;
bool m[18];

void tr(long long x) {
    long long i;
    for (i = 17; i>=0; i--) {
        m[i] = (x%10)%2;
        x = x/10;
    }
}

long long f(long long left) {
    long long res = 0, i;
    for (i = 17; i>left; i--) {
        res += pow2[18-i];
    }
    for (i = 17; i>=left; i--) {
        res += (pow2[17-i]*m[i]);
    }
    return res;
}

int main()
{
//    ifstream fin;
//    fin.open("file.txt");
    long long i, j;
    string s;
    pow2[0] = 1;
    for (i = 1; i<20; i++) pow2[i] = 2*pow2[i-1];
    char c;
    cin >> n;
    for (i = 0; i<c20; i++) ans[i] = 0;
    for (i = 0; i<n; i++) {
        cin >> c;
        if (c == '+') {
            cin >> a;
            tr(a);
            j = 0;
            bool b = 1;
            while (b) {
                ans[f(j)]++;
                if ((m[j] == 1)||(j>=17)) b = 0;
                j++;
            }
        }
        if (c == '-') {
            cin >> a;
            tr(a);
            j = 0;
            bool b = 1;
            while (b) {
                ans[f(j)]--;
                if ((m[j] == 1)||(j>=17)) b = 0;
                j++;
            }
        }
        if (c == '?') {
            cin >> s;
            for (j = 0; j<18; j++) m[j] = 0;
            int k = 0;
            for (j = (18 - s.length()); j<18; j++) {
                if (s[k] == '1') m[j] = 1;
                else m[j] = 0;
                k++;
            }
            cout << ans[f(18-s.length())] << endl;
        }
    }
    return 0;
}