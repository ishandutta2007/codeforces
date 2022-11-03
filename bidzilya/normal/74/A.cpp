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
    string name;
    int a = -MAX_INT,n;
    cin >> n;
    for (int i=0;i<n;i++){
        string tname;
        int m,p,A,B,C,D,E;
        cin >> tname >>  p >> m >> A >> B >> C >> D >> E;
        int ball = p*100 - m*50 + A + B + C + D + E;
        if (ball>a){
            name = tname;
            a = ball;
        }
    }
    cout << name;
    return 0;
}