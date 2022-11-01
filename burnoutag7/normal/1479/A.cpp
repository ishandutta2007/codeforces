#include<bits/stdc++.h>
using namespace std;

int n,a[100005];

int f(int x){
    if(a[x]!=-1)return a[x];
    cout<<"? "<<x<<endl;
    cin>>a[x];
    return a[x];
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    memset(a,-1,sizeof(a));
    a[0]=a[n+1]=n+1;
    int l=1,r=n,m,res;
    while(l<=r){
        m=l+r>>1;
        if(f(m)<f(m+1)){
            res=m;
            r=m-1;
        }else{
            l=m+1;
        }
    }
    cout<<"! "<<res<<endl;

    return 0;
}