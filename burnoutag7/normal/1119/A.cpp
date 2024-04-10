#include<bits/stdc++.h>
using namespace std;

int n;
int c[300005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    int l;
    for(l=2;l<=n;l++){
        if(c[l]!=c[l-1])break;
    }
    int r;
    for(r=n-1;r>0;r--){
        if(c[r]!=c[r+1])break;
    }
    if(c[1]!=c[n]){
        cout<<n-1<<endl;
    }else{
        cout<<max(n-l,r-1)<<endl;
    }

    return 0;
}