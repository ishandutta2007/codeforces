#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

typedef long long ll;
const ll MD = (ll)1e9 + 7;
const double PI = 3.1415926535;
const int MAX_INT = (int)1e9;
const ll MAX_LL = (ll)1e18;
const double eps = 1e-8;

int l[15][1000],r[15][1000];
int c[15];
int h,n;

int main(){
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    cin >> n;
    h = 1;
    l[0][0]=1;
    r[0][0]=n;
    c[0] = 1;
    while (1){
        c[h] = 0;
        for (int i=0;i<c[h-1];i++){
            int len = r[h-1][i]-l[h-1][i]+1;
            if (len>3){
                l[h][c[h]] = l[h-1][i];
                r[h][c[h]] = l[h-1][i]+len/2-1;
                c[h]++;
            }
            if (len>2){
                l[h][c[h]] = l[h-1][i]+len/2;
                r[h][c[h]] = r[h-1][i];
                c[h]++;
            }
        }
        if (c[h]==0)
            break;
        h++;
    }/*
    for (int i=0;i<h;i++){
        for (int j=0;j<c[i];j++)
            cout << l[i][j] << "_" << r[i][j] << "  ";
        cout << endl;
    }*/

    cout << h << endl;
    for (int i=0;i<h;i++){
        vector<int> a;
        for (int j=0;j<c[i];j++){
            int len = r[i][j]-l[i][j]+1;
            for (int k=0;k<len/2;k++)
                a.push_back(l[i][j]+k);
        }
        cout << a.size() << " ";
        for (int j=0;j<a.size();j++)
            cout << a[j] << " ";
        cout << endl;
    }
    return 0;
}