#include <bits/stdc++.h>
using namespace std;

long long n,m,ans;
long long a[2000][2000];
bool y[2000],yy[2000];
int main(){
    cin>>n>>m;
    for (int i=1;i<=n;++i){
            bool t=false;
        for (int j=1;j<=m;++j){
            cin>>a[i][j];
            if (a[i][j]==0){
                if (t==true) ++ans;
                if (y[j]==true) ++ans;
            } else {t=true; y[j]=true;}
        }
    }
    for (int i=n;i>0;--i){
        bool t=false;
        for (int j=m;j>0;--j){
            if (a[i][j]==0){
                if (t==true) ++ans;
                if (yy[j]==true) ++ans;
            } else {
                t=true;
                yy[j]=true;
            }
        }
    }
    cout<<ans;
}