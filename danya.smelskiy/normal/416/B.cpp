#include <bits/stdc++.h>
using namespace std;

int n,m,x,last[10];
int main(){

    cin>>n>>m;
    for (int i=1;i<=n;++i){
        for (int j=1;j<=m;++j){
            cin>>x;
            last[j]=max(last[j-1]+x,last[j]+x);
        }
        cout<<last[m]<<endl;
    }
}