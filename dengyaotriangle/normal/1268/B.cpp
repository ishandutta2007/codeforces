#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=300005;

int n;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    long long c1=0,c2=0;
    for(int i=1;i<=n;i++){
        int a;cin>>a;
        if(i&1){c1+=a/2;c2+=a-a/2;}
        else{c2+=a/2;c1+=a-a/2;}
    }
    cout<<min(c1,c2);
    return 0;
}