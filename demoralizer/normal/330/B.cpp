#include<bits/stdc++.h>
using namespace std;
int a[1001];
int main(){
    int n,m,t;
    cin>>n>>m;
    for(int i=0;i<2*m;i++){
        cin>>t;
        a[t]++;
    }
    for(int i=1;i<=n;i++)if(a[i]==0)t=i;
    cout<<(n-1)<<endl;
    for(int i=1;i<=n;i++){
        if(i==t)continue;
        cout<<t<<" "<<i<<endl;
    }
}