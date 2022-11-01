#include<bits/stdc++.h>
using namespace std;

void mian(){
    int n,sum=0;
    cin>>n;
    for(int i=0,a;i<n;i++){
        cin>>a;
        sum+=a;
    }
    cout<<max(sum-n,(int)(sum!=n))<<'\n';
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