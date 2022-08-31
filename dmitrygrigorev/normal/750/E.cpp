#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <math.h>
#include <fstream>
using namespace std;
int n, q, li, ri;
int INF = 10000000;
string str;
struct matrix{int dp[5][5];};
matrix rmq[800000];
matrix result(int i, int l, int r, int l1, int r1){
    if (l == l1 && r == r1){
        return rmq[i];
    }
    int m = (l + r) / 2;
    if (min(r1, m) <= l1){
        return result(2 * i + 2, m, r, max(l1, m), r1);
    }
    if (max(l1, m) >= r1){
        return result(2 * i + 1, l, m, l1, min(r1, m));
    }
    matrix mat1, mat2, mat3;
    mat1 = result(2 * i + 1, l, m, l1, min(r1, m));
    mat2 = result(2 * i + 2, m, r, max(l1, m), r1);
    for (int j=0;j<=4;j++){
        for (int k=0;k<=4;k++){
            mat3.dp[j][k] = INF;
        }
    }
    for (int j=0;j<=4;j++){
        for (int k=j;k<=4;k++){
            for (int m=j;m<=k;m++){
                mat3.dp[j][k] = min(mat3.dp[j][k], mat1.dp[j][m] + mat2.dp[m][k]);
            }
        }
    }
    return mat3;
}
void create(int i, int l, int r){
    if (l >= r){
        return;
    }
    if (r - l == 1){
        matrix mm;
        for (int j=0;j<=4;j++){
            for (int k=j;k<=4;k++){
                if (k == j){
                    mm.dp[j][k] = 0;
                }
                else{
                    mm.dp[j][k] = INF;
                }
            }
        }
        if (str[l] == '2'){
            mm.dp[0][1] = 0;
            mm.dp[0][0] = 1;
        }
        if (str[l] == '0'){
            mm.dp[1][2] = 0;
            mm.dp[1][1] = 1;
        }
        if (str[l] == '1'){
            mm.dp[2][3] = 0;
            mm.dp[2][2] = 1;
        }
        if (str[l] == '7'){
            mm.dp[3][4] = 0;
            mm.dp[3][3] = 1;
        }
        if (str[l] == '6'){
            mm.dp[3][3] = 1;
            mm.dp[4][4] = 1;
        }
        rmq[i] = mm;
        return;
    }
    int m = (l + r) / 2;
    create(2*i + 1, l, m);
    create(2 * i + 2, m, r);
    matrix mat;
    for (int j=0;j<=4;j++){
        for (int k=j;k<=4;k++){
            mat.dp[j][k] = INF;
            for (int m=j;m<=k;m++){
                mat.dp[j][k] = min(mat.dp[j][k], rmq[2*i + 1].dp[j][m] + rmq[2*i + 2].dp[m][k]);
            }
        }
    }
    rmq[i] = mat;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin >> n >> q;
    cin >> str;
    int data[q][2];
    for (int i=0;i<q;i++){
        cin >> li >> ri;
        data[i][0] = li;
        data[i][1] = ri;
    }
    create(0, 0, str.size());
    for (int i=0;i<q;i++){
        matrix mat = result(0, 0, str.size(), data[i][0] - 1, data[i][1]);
        if (mat.dp[0][4] < INF){
        cout << mat.dp[0][4] << endl;
        }
        else{
            cout << -1 << endl;
        }
    }
    return 0;
}