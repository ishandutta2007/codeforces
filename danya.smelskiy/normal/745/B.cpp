#include <bits/stdc++.h>
using namespace std;

int n,m;
bool t;
int x,y,x2,y2;
char a[501][501];
int main(){
    cin>>n>>m;
    for (int i=1;i<=n;++i){
        for (int j=1;j<=m;++j){
            cin>>a[i][j];
            if (t==false && a[i][j]=='X'){
                t=true;
                x=i;
                y=j;
            }
            if (a[i][j]=='X') {
                x2=i;
                y2=j;
            }
        }
    }
    for (int i=1;i<=n;++i)
        for (int j=1;j<=m;++j){
    if (a[i][j]=='X' && !(i>=x && i<=x2 && j>=y && j<=y2)){
        cout<<"NO";
        return 0;
    }
        if (a[i][j]=='.' && i>=x && i<=x2 && j>=y && j<=y2){
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
}