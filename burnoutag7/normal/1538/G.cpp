#include<bits/stdc++.h>
using namespace std;

int x,y,a,b;

bool chk(long long n){
    return max(0.0,ceil((double)(y-a*n)/(b-a)))<=min((double)n,floor((double)(x-b*n)/(a-b)));
}

void mian(){
    cin>>x>>y>>a>>b;
    if(a==b){
        cout<<min(x,y)/a<<'\n';
        return;
    }
    if(a<b)swap(a,b);
    int l=0,r=1e9,m,res;
    while(l<=r){
        m=l+r>>1;
        if(chk(m)){
            l=m+1;
            res=m;
        }else{
            r=m-1;
        }
    }
    cout<<res<<'\n';
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