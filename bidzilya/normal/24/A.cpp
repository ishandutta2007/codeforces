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

int h[222],nx[222],t[222],c[222];

int go(int v, int p){
    if (v==1)
        return 0;

    int i = h[v];
    if (t[i]==p)
        i = nx[i];
    return c[i]+go(t[i],v);
}

int main(){
    //ifstream cin("input.txt");
   // ofstream cout("output.txt");
    int n;

    cin >> n;
    int m =0;
    for (int i=1;i<=n;i++){
        int A,B,C;
        cin >> A >> B >> C;
        nx[++m]=h[A];
        h[A]=m;
        t[m]=B;
        c[m]=0;
        nx[++m]=h[B];
        h[B]=m;
        t[m]=A;
        c[m]=C;
    }

    int k = h[1];
    int ans = c[k]+go(t[k],1);
    k = nx[k];
    ans = min(ans, c[k]+go(t[k],1));
    cout << ans;

    return 0;
}