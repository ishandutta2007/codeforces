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

int C3(int n){
    return n*(n-1)*(n-2)/6;
}

int C2(int n){
    return n*(n-1)/2;
}

int k;
int n;
int b[101][101];

void add1(int count){
    int nn = n+count;
    for (int i=0;i<n;i++)
        for (int j=n;j<nn;j++)
            b[i][j]=0;
    for (int i=n;i<nn;i++){
        for (int j=0;j<n;j++)
            b[i][j]=0;
        for (int j=n;j<nn;j++)
            b[i][j]=1;
        b[i][i]=0;
    }
    n = nn;
}

void add2(int count){
    for (int i=0;i<=n;i++){
        b[i][n]=0;
        b[n][i]=0;
    }
    for (int i=0;i<count;i++){
        b[i][n]=1;
        b[n][i]=1;
    }
    n++;
}

int main(){
    cin >> k;
    n = 0;
    while (k>0){
        int cnt = 100;
        while (C3(cnt)>k)cnt--;
        k -= C3(cnt);
        add1(cnt);
        while (k>0){
            int cnt2 = cnt;
            while (C2(cnt2)>k)cnt2--;
            add2(cnt2);
            k -= C2(cnt2);
        }
    }

    cout << n << endl;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++)
            cout << b[i][j];
        cout << endl;
    }

    return 0;
}