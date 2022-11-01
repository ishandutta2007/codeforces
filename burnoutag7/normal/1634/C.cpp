#include<bits/stdc++.h>
using namespace std;

void mian(){
    int n,m;
    cin>>n>>m;
    if(m==1){
        cout<<"YES\n";
        for(int i=1;i<=n;i++)cout<<i<<'\n';
    }else if(n&1^1){
        cout<<"YES\n";
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cout<<(i&1?i*m-m+j*2-1:i*m-2*m+j*2)<<' ';
            }
            cout<<'\n';
        }
    }else{
        cout<<"NO\n";
    }
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