#include<bits/stdc++.h>
using namespace std;

int n,k,h[200005],lb[200005],rb[200005];

void mian(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>h[i];
    }
    lb[1]=h[1]+1;
    rb[1]=h[1]+k;
    for(int i=2;i<=n;i++){
        lb[i]=max(h[i]+1,lb[i-1]-k+1);
        rb[i]=min(h[i]+k-1+k,rb[i-1]+k-1);
        if(lb[i]+k-1>rb[i]){
            cout<<"nO\n";
            return;
        }
    }
    if(lb[n]==h[n]+1)cout<<"yEs\n";
    else cout<<"nO\n";
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