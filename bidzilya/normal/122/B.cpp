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

int ta = 0;
string l,s;

bool happy(string s){
    for (int i=0;i<s.length();i++)
        if (s[i]!='4' && s[i]!='7')
            return false;
    return true;
}

void check(string m){
    int k = 0;
    for (int i=0;i<s.length();i++)
        for (int j=i;j<s.length();j++){
            string t = s.substr(i,j-i+1);
            if (t==m)
                k++;
        }
    if (k>ta || k==ta && m<l){
        l = m;
        ta = k;
    }
}

int main(){
    cin >> s;
    for (int i=0;i<s.length();i++)
        for (int j=i;j<s.length();j++){
            string t = s.substr(i,j-i+1);
            if (happy(t))
                check(t);
        }
    if (ta==0)
        cout << -1;
    else
        cout << l;
    return 0;
}