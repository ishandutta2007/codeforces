#include<bits/stdc++.h>
using namespace std;

void mian(){
    int n,m,k;
    cin>>n>>m>>k;
    cout<<(max(n,m)*min(n,m)-1==k?"YES\n":"NO\n");
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