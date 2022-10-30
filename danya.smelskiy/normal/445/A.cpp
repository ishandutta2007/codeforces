#include <bits/stdc++.h>
using namespace std;
long long n,m;
string s;
char a[1000][1000];
int main(){
    cin>>n>>m;
    for (int i=1;i<=n;++i){
        cin>>s;
        for (int j=1;j<=m;++j){
            a[i][j]=s[j-1];
        }
    }
    for (int i=1;i<=n;++i){
        for (int j=1;j<=m;++j)
        if (a[i][j]=='.'){
            if ((i+j)%2==0) a[i][j]='B';
            else a[i][j]='W';
        }
    }
    for (int i=1;i<=n;++i){
        for (int j=1;j<=m;++j)
            cout<<a[i][j];
        cout<<'\n';
    }
}