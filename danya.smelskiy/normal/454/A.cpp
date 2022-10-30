#include <bits/stdc++.h>
using namespace std;
int a[1001][1001];
int n,last;
int j;
int main(){
    cin>>n;
    last=n/2+1;
    while (last>0){
        ++j;
        for (int i=last;i<=n-last+1;++i)
            a[j][i]=1;
        --last;
    }
    last=1;
    while (last<=n/2+1){
        ++j;
        ++last;
        for (int i=last;i<=n-last+1;++i)
            a[j][i]=1;
    }
    for (int i=1;i<=n;++i){
        for (int j=1;j<=n;++j)
            if (a[i][j]==1) cout<<"D";
        else cout<< "*";
        cout<<endl;
    }
}