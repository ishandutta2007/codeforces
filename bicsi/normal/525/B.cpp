#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;
typedef int var;

#define fin cin
#define fout cout

#define MAXN 300001

bool V[MAXN];
char str[MAXN];

int main() {

    //freopen("2.in", "r", stdin);
    //freopen("2.out", "w", stdout);

    fin>>str+1;
    var m, a;
    str[0] = '#';
    fin>>m;
    var n = strlen(str)-1;

    while(m--) {
        fin>>a;
        V[a] ^= 1;
        V[n-a+2] ^= 1;
    }

    bool ch = 0;
    for(var i=1; i<=n; i++) {
        ch ^= V[i];
        if(ch == 1) {
            fout<<str[n-i+1];
        } else {
            fout<<str[i];
        }
    }

    return 0;
}