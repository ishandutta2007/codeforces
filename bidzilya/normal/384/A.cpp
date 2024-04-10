// Codeforces Round 225 (Div. 2): A

#include <iostream>
#include <vector>
using namespace std;

const char OCCUP_SYMB = 'C';
const char EMPTY_SYMB = '.';

int GetCount(const vector<vector<char>>& table, char symb) {
    int result = 0;
    for (int i = 0; i < (int) table.size(); ++i) {
        for (int j = 0; j < (int) table[i].size(); ++j) {
            result += (table[i][j] == symb);
        }
    }
    return result;
}

void BuildTableWithShift(vector<vector<char>>& table, int shift, int n) {
    table.assign(n, vector<char>(n, EMPTY_SYMB));
    for (int i = 0; i < n; ++i) {
        int curShift = (shift + i) & 1;

        for (int j = curShift; j < n; j += 2) {
            table[i][j] = OCCUP_SYMB;
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<vector<char>> table[2];

    BuildTableWithShift(table[0], 0, n);
    BuildTableWithShift(table[1], 1, n);

    if (GetCount(table[0], OCCUP_SYMB) < GetCount(table[1], OCCUP_SYMB)) {
        swap(table[0], table[1]);
    }

    cout << GetCount(table[0], OCCUP_SYMB) << '\n';
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << table[0][i][j];
        }
        cout << '\n';
    }
    cout.flush();

    return 0;
}