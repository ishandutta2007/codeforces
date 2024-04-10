#include <iostream>
#include <cstdio>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <stack>
#include <map>
#include <set>

#define F first
#define S second

using namespace std;

    string a, b;
    int b_l, a_l, l, r, j;

int main(){
    //freopen("avia.in", "r", stdin);
    //freopen("avia.out", "w", stdout);
    cin >> a >> b;
    b_l = b.length();
    a_l = a.length();
    for(int i=0; i<b_l; i++){
        if(a[j] == b[i] && j<a_l-1)j++; else
            if(a[j] == b[i]) {l=i+1; break;}
    }
    //cout << j;
    for(int i=b_l-1; i>=0; i--){
        if(a[j] == b[i] && j>0)j--; else
            if(a[j] == b[i]) {j=0; r=i-1; break;}
    }
    if(l==0 || r==0)cout << 0; else
    if(l>r+1) cout << 0; else cout << r-l+2;
}