#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int n, m;
    cin >> n >> m;
    char c[n][m];
    int x[4], y[4], h = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> c[i][j];
            if(c[i][j] == '*'){
                x[h] = i;
                y[h] = j;
                h++;
                //cout << h << endl;
            }
        }
    }
    if(x[0] == x[1]){
        x[3] = x[2];
    }else if(x[1] == x[2]){
        x[3] = x[0];
    }else{
        x[3] = x[1];
    }
    if(y[0] == y[1]){
        y[3] = y[2];
    }else if(y[1] == y[2]){
        y[3] = y[0];
    }else{
        y[3] = y[1];
    }
    cout << x[3] + 1 << ' ' << y[3] + 1;
}