#include <bits/stdc++.h>
using namespace std;

int n;
int ans;

int main(){
    cin>>n;
    for (int i=1;i<=n;++i)
    for (int j=i;j<=n;++j){
        int x=i*i+j*j;
        int y=sqrt(x);
        if (y*y==x && y<=n) ++ans;
    }
    cout<<ans;
}