#include <cstdio>
#include <iostream>

#define FOR(i, a, b) for (int i=a; i<b; i++)

using namespace std;

int n,m,k, s[101000],b[1010][1010];;
char a[1010][1010];

int f(int x,int y,int c){
    if (a[x][y] == '*') return 1;
    if (b[x][y]) return 0;
    b[x][y] = c;
    return f(x+1,y,c)+f(x-1,y,c)+f(x,y+1,c)+f(x,y-1,c);
}

int main() {
    cin >> n >> m >> k;
    FOR(i,1,n+1) cin >> (a[i]+1);
    FOR(i,1,k+1) {
        int x,y,now;
        cin >> x >> y;
        if (b[x][y]) now = s[b[x][y]];
        else now = f(x,y,i),s[i] = now;
        cout << now << endl;
    }
}