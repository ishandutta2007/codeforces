#include<bits/stdc++.h>
using namespace std;

int n,x,w[105],sum;

void mian(){
    cin>>n>>x;
    sum=0;
    for(int i=1;i<=n;i++){
        cin>>w[i];
        if(sum==x){
            sum+=w[i];
            swap(w[i],w[i-1]);
        }else sum+=w[i];
    }
    if(sum==x){
        cout<<"NO\n";
    }else{
        cout<<"YES\n";
        for(int i=1;i<=n;i++)cout<<w[i]<<' ';
        cout<<'\n';
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