#include <bits/stdc++.h>
using namespace std;


int n,m;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    cout<<(6*n-1)*m<<'\n';
    for (int i=1;i<=n;++i) {
        int x=(6*(i-1));
        cout<<(x+1)*m<<" "<<(x+2)*m<<" "<<(x+3)*m<<" "<<(x+5)*m<<'\n';
    }
}