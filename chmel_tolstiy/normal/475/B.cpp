#include <iostream>
#include <string>

using namespace std;

int main() {
    int n, m; cin >> n >> m;
    string row; cin >> row;
    string col; cin >> col;
    
    bool ok = true;
    char r, c;

    r = row[0], c = col[0];
    if (r == '<' && c == '^') ok = false;
    if (r == '>' && c == 'v') ok = false;

    r = row[row.length()-1], c = col[col.length() - 1];
    if (r == '<' && c == '^') ok = false;
    if (r == '>' && c == 'v') ok = false;
    
    r = row[0]; c = col[col.length() - 1];
    if (r == '<' && c == 'v') ok = false;
    if (r == '>' && c == '^') ok = false;
    
    if (ok)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    
    return 0;
}