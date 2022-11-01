#include<bits/stdc++.h>
using namespace std;

int calc(int a,int b){
    int c=min(a-b,b);
    a-=c*2;b-=c;
    return c+min(a,b)/3*2+(max(a%3,b%3)>=2&&min(a%3,b%3)>=1);
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--){
        int a,b;
        cin>>a>>b;
        cout<<calc(max(a,b),min(a,b))<<endl;
    }

    return 0;
}