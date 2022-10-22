#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin >> n >> m;
    string s[n];
    int a[m];
    int g[m][5];
    for(int i=0; i<m; i++){
        for(int j=0; j<5; j++){
            g[i][j]=0;
        }
    }
    for(int i=0; i<n; i++){
        cin >> s[i];
        for(int j=0; j<m; j++){
            g[j][s[i][j]-'A']++;
        }
    }
    for(int i=0; i<m; i++){
        cin >> a[i];
    }
    int cnt=0;
    for(int i=0; i<m; i++){
        int m=0;
        for(int j=0; j<5; j++){
            if(g[i][j]>m) m=g[i][j];
        }
        cnt+=m*a[i];
    }
    cout << cnt;
    return 0;
}