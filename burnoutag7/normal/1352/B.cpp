#include<bits/stdc++.h>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        if(n&1){
            if(n>=k&&(k&1)){
                cout<<"YES\n";
                for(int i=0;i+1<k;i++)cout<<1<<' ';
                cout<<n-k+1<<'\n';
            }else{
                cout<<"NO\n";
            }
        }else{
            if(n>=k<<1){
                cout<<"YES\n";
                for(int i=0;i+1<k;i++)cout<<2<<' ';
                cout<<n-((k-1)<<1)<<'\n';
            }else
            if(!(k&1)&&n>=k){
                cout<<"YES\n";
                for(int i=0;i+1<k;i++)cout<<1<<' ';
                cout<<n-(k-1)<<'\n';
            }else{
                cout<<"NO\n";
            }
        }
    }

    return 0;
}