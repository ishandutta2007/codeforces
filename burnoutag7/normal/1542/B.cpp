#include<bits/stdc++.h>
using namespace std;

void mian(){
    int n,a,b;
    cin>>n>>a>>b;
    if(a==1){
        cout<<(n%b==1%b?"Yes\n":"No\n");
    }else{
        for(long long x=1;x<=n;x*=a)if((n-x)%b==0){
            cout<<"Yes\n";
            return;
        }
        cout<<"No\n";
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