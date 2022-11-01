#include<bits/stdc++.h>
using namespace std;

void mian(){
    int n;
    cin>>n;
    vector<int> x(n),y(n);
    for(int &a:x)cin>>a;
    for(int i=0;i+1<n;i++){
        y[i+1]=x[i]&~(x[i+1]&x[i]);
        x[i+1]|=y[i+1];
    }
    for(int &a:y)cout<<a<<' ';
    cout<<'\n';
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--)mian();

    return 0;
}