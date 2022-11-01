#include<bits/stdc++.h>
using namespace std;

int n,k;

void mian(){
    cin>>n>>k;
    k--;
    cout<<(k/(n>>1)*(n+1>>1)+k%(n>>1))%n+1<<'\n';
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