#include<bits/stdc++.h>
using namespace std;

int inp(){
    int res;
    cin>>res;
    return res;
}

int n,p;

void left(){
    int l=1,r=p-1,m,res;
    while(l<=r){
        m=l+r>>1;
        cout<<"? "<<m<<' '<<p<<endl;
        if(inp()==p){
            l=m+1;
            res=m;
        }else{
            r=m-1;
        }
    }
    cout<<"! "<<res<<endl;
}

void right(){
    int l=p+1,r=n,m,res;
    while(l<=r){
        m=l+r>>1;
        cout<<"? "<<p<<' '<<m<<endl;
        if(inp()==p){
            r=m-1;
            res=m;
        }else{
            l=m+1;
        }
    }
    cout<<"! "<<res<<endl;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    cout<<"? 1 "<<n<<endl;
    cin>>p;
    if(p!=1){
        cout<<"? 1 "<<p<<endl;
        if(inp()==p){
            left();
        }else{
            right();
        }
    }else{
        right();
    }

    return 0;
}