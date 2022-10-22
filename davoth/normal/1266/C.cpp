#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
const int N = 1e2 + 10;

int r,c;
int main(){
    fast_io;
    cin >> r >> c;
    int a[r][c];
    if(r==1 && c==1) return cout << 0,0;
    if(c==1){
        for(int i=1; i<=r; i++) cout << i+1 << '\n';
        return 0;
    }
    for(int i=0; i<c; i++) a[0][i]=i+2;
    for(int i=1; i<r; i++){
        for(int j=0; j<c; j++){
            a[i][j]=a[0][j]*(c+i+1);
        }
    }
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++) cout << a[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}