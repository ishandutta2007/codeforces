#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
    cin>>n;
    if (n%2==0) cout<<(n*n)/2<<endl;
    else cout<<(n*n)/2+1<<endl;
    for (int i=1;i<=n;++i){
        for (int j=1;j<=n;++j){
            if (i%2==1 && j%2==1) cout<<"C";
            else if (i%2==0 && j%2==0) cout<<"C";
            else cout<<".";
        }
        cout<<'\n';
    }
}