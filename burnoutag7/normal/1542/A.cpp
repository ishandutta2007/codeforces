#include<bits/stdc++.h>
using namespace std;

void mian(){
    int n,c=0;
    cin>>n;
    for(int i=0,a;i<n*2;i++){
        cin>>a;
        c+=a&1;
    }
    cout<<(c==n?"Yes\n":"No\n");
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