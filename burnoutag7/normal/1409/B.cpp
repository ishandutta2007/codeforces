#include<bits/stdc++.h>
using namespace std;

int n,a,b,x,y;

void mian(){
    cin>>a>>b>>x>>y>>n;
    if(max(a-n,x)>max(b-n,y)){
        swap(a,b);
        swap(x,y);
    }
    if(a-n>x){
        a-=n;
        n=0;
    }else{
        n-=a-x;
        a=x;
    }
    b=max(b-n,y);
    cout<<(long long)a*b<<'\n';
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