#include<bits/stdc++.h>
using namespace std;

int n,a[200005];

void mian(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    bool f=false;
    for(int i=1;i<n;i++){
        if(a[i]!=a[i+1])f=true;
    }
    if(f)cout<<"1\n";
    else cout<<n<<'\n';
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--){
        mian();
    }

    return 0;
}