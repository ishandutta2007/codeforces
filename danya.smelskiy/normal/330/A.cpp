#include <bits/stdc++.h>
using namespace std;

bool usedh[100],usedv[100];
int a[100][100];
int n,m,ans;
string s;
int main(){
    cin>>n>>m;
    for (int i=1;i<=n;++i){
        cin>>s;
        for (int j=1;j<=m;++j)
        if (s[j-1]=='S') {
            a[i][j]=1;
            usedh[i]=true;
            usedv[j]=true;
        } else a[i][j]=0;
    }
    for (int i=1;i<=n;++i){
        for (int j=1;j<=m;++j){
            if (a[i][j]==0 && (usedh[i]==false || usedv[j]==false)) ++ans;
        }
    }
    cout<<ans;
}