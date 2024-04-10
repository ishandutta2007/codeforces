#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,q;
ll bit[100005],b,c;

ll sum(int pos){
    ll res=0;
    while(pos>0){
        res+=bit[pos];
        pos-=pos&-pos;
    }
    return res;
}

void add(int pos,int val){
    while(pos<=n){
        bit[pos]+=val;
        pos+=pos&-pos;
    }
}

void update(int l,int r,int x){
    if(l!=1){
        if(sum(l)>=sum(l-1)){
            b-=sum(l)-sum(l-1);
        }else{
            c-=sum(l)-sum(l-1);
        }
    }
    if(r!=n){
        if(sum(r+1)>=sum(r)){
            b-=sum(r+1)-sum(r);
        }else{
            c-=sum(r+1)-sum(r);
        }
    }
    add(l,x);
    add(r+1,-x);
    if(l!=1){
        if(sum(l)>=sum(l-1)){
            b+=sum(l)-sum(l-1);
        }else{
            c+=sum(l)-sum(l-1);
        }
    }
    if(r!=n){
        if(sum(r+1)>=sum(r)){
            b+=sum(r+1)-sum(r);
        }else{
            c+=sum(r+1)-sum(r);
        }
    }
}

void print(){
    ll b1=0,c1=sum(1);
    cout<<(b1+b+c1+1+(ll)2e18)/2-(ll)1e18<<'\n';
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        add(i,a);
        add(i+1,-a);
        if(i!=1){
            if(sum(i)>=sum(i-1)){
                b+=sum(i)-sum(i-1);
            }else{
                c+=sum(i)-sum(i-1);
            }
        }
    }
    print();
    cin>>q;
    while(q--){
        int l,r,x;
        cin>>l>>r>>x;
        update(l,r,x);
        print();
    }

    return 0;
}