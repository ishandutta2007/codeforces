#include<bits/stdc++.h>
using namespace std;

const int V=500001;
int n,x,a[500005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>x;
    for(int i=1;i<=n;i++){
        int b;
        cin>>b;
        a[b]++;
    }
    for(int i=1;i<=V;i++){
        a[i+1]+=a[i]/(i+1);
        a[i]%=i+1;
        if(a[i]&&i<x){
            cout<<"No\n";
            return 0;
        }
    }
    cout<<"Yes\n";

    return 0;
}