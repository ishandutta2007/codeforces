#include<bits/stdc++.h>
using namespace std;

int n,x,a[1005],sum,diff,same;

void mian(){
    cin>>n>>x;
    sum=0;
    diff=0;
    same=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
        diff|=a[i]!=x;
        same|=a[i]==x;
    }
    if(!diff){
        cout<<"0\n";
    }else if(sum==n*x||same){
        cout<<"1\n";
    }else cout<<"2\n";
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