#include <bits/stdc++.h>

using namespace std;
typedef int var;
typedef pair<var, var> Pair;

var T[500000];

#define DIM 100000
char buff[DIM];
var poz = DIM - 1;
void Read(var &a) {
    while(!isdigit(buff[poz]))
        if(++poz == DIM)
            cin.read(buff, DIM), poz=0;
    a = 0;
    while(isdigit(buff[poz])) {
        a = a * 10 + buff[poz] - '0';
        if(++poz == DIM)
            cin.read(buff, DIM), poz=0;
    }
}



    int n, k, a;

vector<var> Stop;
bool good(var t) {
    Stop.clear();
    Stop.push_back(0);
    for(int i=1; i<=n; i++)
        if(T[i] <= t)
            Stop.push_back(i);
    Stop.push_back(n+1);

    var cnt = 0;

    for(int i=1; i<Stop.size(); i++) {
        var sz = Stop[i] - Stop[i-1] - 1;
        if(sz <= 0) continue;
        while(sz >= a) {cnt++; sz-=a+1;}
    }

    return cnt >= k;
}


int main() {
    #ifndef ONLINE_JUDGE
    freopen("debug.in", "r", stdin);
    #endif // ONLINE_JUDGE

    Read(n); Read(k); Read(a);

    int m, x;
    Read(m);


    for(int i=1; i<=n; i++) T[i] = m+10;

    for(int i=1; i<=m; i++) {
        Read(x);
        T[x] = min(T[x], i);
    }

    int M, sol=0;
    for(M=1; M<=m; M<<=1);
    for(;M;M>>=1) {
        if(M+sol<=m && good(M+sol))
            sol+=M;
    }

    if(sol >= m) {cout<<-1;}
    else {cout<<sol+1;}

    //cerr<<good(6);

    return 0;
}