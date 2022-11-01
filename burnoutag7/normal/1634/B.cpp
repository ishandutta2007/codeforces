#include<bits/stdc++.h>
using namespace std;

void mian(){
    long long n,x,y,a,b=0;
    cin>>n>>x>>y;
    while(n--){
        cin>>a;
        b^=a;
    }
    cout<<((b^x^y)&1?"Bob\n":"Alice\n");
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