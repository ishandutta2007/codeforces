#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,m;
    cin >> n >> m;
    int a[n+1][m+1];
    bool c[n+1][m+1];
    for(int i=0; i<=n; i++) for(int j=0; j<=m; j++){
        c[i][j]=false;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> a[i][j];
        }
    }
    for(int i=0; i<=n; i++) a[i][m]=0;
    for(int i=0; i<=m; i++) a[n][i]=0;
    vector<pair<int,int> > moves;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(a[i][j]==1 && a[i][j+1]==1 && a[i+1][j]==1 && a[i+1][j+1]==1){
                moves.push_back(make_pair(i+1,j+1));
                c[i][j]=true;
                c[i][j+1]=true;
                c[i+1][j]=true;
                c[i+1][j+1]=true;
            }else if(c[i][j]){
                continue;
            }else if(a[i][j]!=0){
                cout << -1;
                return 0;
            }
        }
    }
    cout << moves.size() << '\n';
    for(int i=0; i<moves.size(); i++){
        cout << moves[i].first << ' ' << moves[i].second << '\n';
    }
    return 0;
}