#include<bits/stdc++.h>
using namespace std;

void mian(){
    int n;
    cin>>n;
    bool valid=1;
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        bool dv=0;
        for(int j=2;j<=i+1;j++)if(a%j){
            dv=1;
            break;
        }
        valid&=dv;
    }
    cout<<(valid?"YES\n":"NO\n");
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