#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<unordered_map>

using namespace std;
typedef int var;

var V[200001], U[200001], I[200001];
var n;

#define DIM 100000
char buff[DIM];
var poz;
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

#define term(a) (V[I[a]]+I[a]-(a))

int main() {

    #ifndef ONLINE_JUDGE
    freopen("debug.in", "r", stdin);
    freopen("debug.out", "w", stdout);
    #endif // ONLINE_JUDGE


    cin.read(buff, DIM);
    Read(n);
    for(var i=1; i<=n; i++) {
        Read(V[i]);
        I[i] = i;
    }

    sort(I+1, I+n+1, [](var a, var b) {
            return V[a] + a < V[b] + b;
         });

    for(var i=1; i<=n; i++) {
        if(term(i) < 0) {
            cout<<":(";
            return 0;
        }
    }

    for(var i=1; i<n; i++) {
        if(term(i) > term(i+1)) {
            cout<<":(";
            return 0;
        }
    }

    for(var i=1; i<=n; i++) {
        cout<<term(i)<<" ";
    }

    return 0;
}