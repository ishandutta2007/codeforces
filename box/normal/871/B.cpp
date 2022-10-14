// writer: w33z8kqrqk8zzzx33
#include <bits/stdc++.h>
using namespace std;


#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, a)
#define rep1(i, a) iter(i, 1, (a)+1)

using ll=long long;

struct op {
    int x, y, re;
} ops[10004];

int ar[5005];
int iar[5005];

bool chk(int n){
    rep(i,n)iar[ar[i]]=i;
    rep(i,2*n)if((ar[ops[i].x]^iar[ops[i].y])!=ops[i].re)return 0;
    //rep(i,n)rep(j,n)if((v1[i]^v1[j])!=(ar[i]^ar[j]))return 0;
    //rep(i,n)rep(j,n)if((v2[i]^v2[j])!=(iar[i]^iar[j]))return 0;
    return 1;
}

void gen(int n,int a0){
    ar[0]=a0;
    rep1(i,n-1)ar[i]=ops[0].re^ops[i].re^a0;
}

bool debug=0;

int targar[5005], targiar[5005];

int cx=0;

int ask(int i,int j){
    cout<<"? "<<i<<' '<<j<<endl;
    int re;
    if(debug)re=targar[i]^targiar[j];
    else cin>>re;
    ops[cx++]={i,j,re};
    return re;
}

signed main() {
    int n;cin >> n;
    if(debug){
        rep(i,n)cin>>targar[i];
        rep(i,n)targiar[targar[i]]=i;
    }
    rep(i,n)ask(i,0);
    rep(i,n)ask(0,i);
    int L=0,a=0;
    rep(i,n){
        gen(n,i);
        if(chk(n)){L=i;a++;}
    }
    cout<<"!"<<endl;
    cout<<a<<endl;
    gen(n,L);
    rep(i,n){
        cout<<ar[i];
        if(i!=n-1)cout<<' ';
    }
    cout<<endl;
}