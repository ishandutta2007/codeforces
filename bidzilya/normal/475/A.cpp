#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int k;
    cin >> k;
    cout << "+------------------------+" << endl;
    vector<int> a(11);
    vector<int> c(11, 3);
    c[0] = 4;
    for (int i = 0; i < 11; ++i) {
        if (k > 0) {
            int d = min(c[i], k);
            k -= d;
            a[i] = d;
        }
    }
    for (int i = 0; i < 4; ++i) {
        cout << "|";
        if (i == 2) {
            if (a[0] >= 3) {
                cout << "O";
            } else {
                cout << "#";
            }
            cout << ".....................";
        } else {
            for (int j = 0; j < 11; ++j) {
                if (i != 3) {
                    if (a[j] >= i + 1) {
                        cout << "O";
                    } else {
                        cout << "#";
                    }
                } else {
                    if (a[j] == c[j]) {
                        cout << "O";
                    } else {
                        cout << "#";
                    }
                }
                cout << ".";
            }
        }
        if (i == 2) {
            cout << ".";
        } else {
            cout << "|";
        }
        if (i == 0) {
            cout << "D";
        } else {
            cout << ".";
        }
        cout << "|";
        if (i == 0 || i == 3) {
            cout << ")"; 
        }
        cout << endl;
    }
    cout << "+------------------------+" << endl;
    
    return 0;
}