#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int v[10][10];

bool wi() {
    for(int i=1;i<=4;i++) {
        for(int j=1;j<=4;j++) {
            if(v[i][j] && v[i+1][j] && v[i+2][j])
                return 1;
            if(v[i][j] && v[i][j+1] && v[i][j+2])
                return 1;
            if(v[i][j] && v[i+1][j+1] && v[i+2][j+2])
                return 1;
        }
    }
    for(int i=1;i<=4;i++) {
        for(int j=3;j<=4;j++) {
            if(v[i][j] && v[i+1][j-1] && v[i+2][j-2])
                return 1;
        }
    }
    return 0;
}

bool pot[10][10];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    for(int i=1;i<=4;i++) {
        string a;
        cin>>a;
        for(int j=1;j<=4;j++) {
            if(a[j-1]=='x') {
                v[i][j]=1;
            }
            if(a[j-1]=='.') {
                pot[i][j]=1;
            }
        }
    }
    for(int i=1;i<=4;i++) {
        for(int j=1;j<=4;j++) {
            if(pot[i][j]) {
                v[i][j]=1;
                if(wi()) {
                    cout<<"YES\n";
                    return 0;
                }
                v[i][j]=0;
            }
        }
    }
    cout<<"NO\n";
    return 0;
}
/**

**/