#include <bits/stdc++.h>
using namespace std;
int n;
int a[1001][1001];
int now;
string s;
int main(){
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>s;
        for (int j=1;j<=n;++j)
            if (s[j-1]=='o') a[i][j]=1;
    }
    for (int i=1;i<=n;++i){
        for (int j=1;j<=n;++j){
            now=0;
            if (a[i][j+1]==1) ++now;
            if (a[i][j-1]==1) ++now;
            if (a[i+1][j]==1) ++now;
            if (a[i-1][j]==1) ++now;
            if (now%2==1){
                cout<<"NO";
                return 0;
            }
        }
    }
    cout<<"YES";
}