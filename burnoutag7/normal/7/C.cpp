#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll A,B,C;

void exGCD(ll a,ll b,ll &r,ll &s,ll &g){
    if(b==0){
        s=0;r=1;g=a;return;
    }
    exGCD(b,a%b,s,r,g);
    s-=a/b*r;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>A>>B>>C;
    ll r,s,g;
    exGCD(A,B,r,s,g);
    if(C%g){
        cout<<-1<<endl;
        return 0;
    }
    cout<<-C/g*r<<' '<<-C/g*s<<endl;

    return 0;
}