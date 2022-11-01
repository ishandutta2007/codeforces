#include<bits/stdc++.h>
using namespace std;

void mian(){
    int n;
    cin>>n;
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            if(n&1^1&&j-i==(n>>1)){
                cout<<"0 ";
            }else if(j-i<=n>>1){
                cout<<"1 ";
            }else{
                cout<<"-1 ";
            }
        }
    }
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