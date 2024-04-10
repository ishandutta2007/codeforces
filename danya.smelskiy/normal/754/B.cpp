#include <bits/stdc++.h>
using namespace std;
string s;
bool ans=false;
long long a[10][10];

int main(){
    for (int i=1;i<=4;++i){
        cin>>s;
        for (int j=0;j<4;++j)
            if (s[j]=='x') a[i][j+1]=1;
            else if (s[j]=='o') a[i][j+1]=100000000;
            else a[i][j+1]=0;
    }
    for (int i=1;i<=4;++i){
        for (int j=1;j<=4;++j){
            if (i<=2){
                if (a[i][j]+a[i+1][j]+a[i+2][j]==2) ans=true;
            }
            if (j<=2) {
                if (a[i][j]+a[i][j+1]+a[i][j+2]==2) ans=true;
            }
            if (i<=2 && j<=2) {
                if (a[i][j]+a[i+1][j+1]+a[i+2][j+2]==2) ans=true;
            }
            if (i>=3 && j<=2){
                if (a[i][j]+a[i-1][j+1]+a[i-2][j+2]==2) ans=true;
            }
        }
    }
    if (ans==true) cout<<"YES";
    else cout<<"NO";
}