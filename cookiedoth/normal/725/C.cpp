#include <bits/stdc++.h>

using namespace std;

string s;
char rep, ans[13][2];
int l, r, dif, posI, posJ, ii, jj;

int main()
{
    cin >> s;
    int i, j;
    for (i = 0; i<27; i++) {
        for (j = 0; j<i; j++) {
            if (s[i] == s[j]) {
                l = j;
                r = i;
                rep = s[i];
            }
        }
    }
    dif = (r - l) - 1;
    if (dif == 0) {
        cout << "Impossible";
        return 0;
    }
    posI = dif/2;
    posJ = dif%2;
  //  cout << "PosI = " << posI << " PosJ = " << posJ << endl;
    ans[posI][posJ] = rep;
    if (posJ == 1) {
        ii = posI;
        jj = 0;
    }
    else {
        ii = posI - 1;
        jj = 1;
    }
    for (i = l+1; i < r; i++) {
        ans[ii][jj] = s[i];
        if (jj != posJ) {
            if (ii > 0) ii--;
            else jj = posJ;
        }
        else ii++;
    }
    if (posJ == 1) {
        ii = posI + 1;
        jj = 1;
    }
    else {
        ii = posI;
        jj = 1;
    }
    int ind;
    if (l > 0) ind = l-1;
    else ind = 26;
    for (i = 0; i<l+(26-r); i++) {
      //  cout << "ii = " << ii << " jj = " << jj << endl;
        ans[ii][jj] = s[ind];
        if ((jj == 1) && (ii < 12)) ii++;
        else {
            if (jj == 0) ii--;
            else jj = 0;
        }
        if (ind != 0) ind--;
        else ind = 26;
    }
    for (i = 0; i<13; i++) cout << ans[i][0];
    cout << endl;
    for (i = 0; i<13; i++) cout << ans[i][1];
    return 0;
}