#include<bits/stdc++.h>
using namespace std;

int n;
long long dat[2000005];

void upd(int k,int a){
    bool f=0;
    k+=n-1;
    dat[k]=a;
    while(k>0){
        k=(k-1)/2;
        if(f){
            dat[k]=dat[k*2+1]^dat[k*2+2];
            f=0;
        }else{
            dat[k]=dat[k*2+1]|dat[k*2+2];
            f=1;
        }
    }
}

int rmq(int a,int b,int k,int l,int r){
    if(r<=a||b<=l)return 1e9;
    if(a<=l && r<=b)return dat[k];
    int vl=rmq(a,b,k*2+1,l,(l+r)/2);
    int vr=rmq(a,b,k*2+2,(l+r)/2,r);
    return min(vl,vr);
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N,m;
    cin>>N>>m;
    n=pow(2,N);
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        upd(i,t);
    }
    for(int i=0;i<m;i++){
        int a,k;
        cin>>k>>a;
        upd(k-1,a);
        cout<<dat[0]<<endl;
    }

    return 0;
}