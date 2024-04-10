#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int n,m;
    cin >> n >> m;
    int a[60][60],b[60][60] = { };
    int k;
    vector< pair<int,int> > AA;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
 
    for(int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if(a[i][j] == a[i][j+1] && a[i][j] == a[i+1][j] && a[i][j] == a[i+1][j+1] && a[i][j] == 1){
                AA.emplace_back(i+1,j+1);
                b[i][j] = 1;
                b[i][j+1] = 1;
                b[i+1][j] = 1;
                b[i+1][j+1] = 1;
            }
        }
    }
    bool flag = 1;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++) {
            if(a[i][j] != b[i][j]){
                flag = 0;
                break;
            }
        }
    }
    if(flag){
        cout << AA.size() << endl;
        for(auto x:AA){
            cout << x.first <<" "<< x.second << endl;
        }
    }else{
        cout << "-1" << endl;
    }
    return 0;
}