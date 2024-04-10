#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <iterator>
using namespace std;
#define MAX_INT (int)10e9
#define MAX_INT64 (__int64)10e18
#define eps 1e-8

#define open_ins() ifstream cin("input.txt")
#define open_outs() ofstream cout("output.txt");
#define open_outf() freopen("output.txt","w",stdout)
#define open_inf() freopen("input.txt","r",stdin)

int main(){
    int n;
    cin >> n;
    int tek=1, k=1;
    for (int i=1;i<n;i++){
        if (tek+k>n)
            tek = k + tek - n;
        else
            tek += k;
        cout << tek << ' ';
        k++;
    }
    return 0;
}