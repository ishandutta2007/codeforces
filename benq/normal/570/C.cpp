#include <iostream>

using namespace std;

int n, m, sum;
int array1[300000];
string s;

void test(string x) {
    for (int i = 0; i < x.length()-1; ++i) {
        if (x[i] == '.' && x[i+1] == '.') {
            array1[i] = 1;
            sum++;
        }
    }
}

int main() {
    cin >> n >> m >> s;
    test(s);
    for (int i = 0; i < m; ++i) {
        int a;
        char b;
        cin >> a >> b;
        char x = s[a-1];
        s[a-1] = b;
        if (array1[a-2] && a != 1) {
            sum--;
            array1[a-2] = 0;
        }
        if (array1[a-1] && a != n) {
            sum--;
            array1[a-1] = 0;
        }
        if (s[a-2] == '.' && s[a-1] == '.' && a != 1) {
            sum++;
            array1[a-2] = 1;
        }
        if (s[a-1] == '.' && s[a] == '.' && a != n) {
            sum++;
            array1[a-1] = 1;
        }
        cout << sum << endl;
    }
}