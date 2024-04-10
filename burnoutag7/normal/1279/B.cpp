#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int t,n,s;
int a[100005];
ll f[100005];

int check(int pos){
    int l=0,r=n,m,res;
    while(l<=r){
        m=(l+r)>>1;
        if(f[m]-(m>=pos?a[pos]:0)<=s){
            res=m;
            l=m+1;
        }else{
            r=m-1;
        }
    }
    return res-(bool(pos>0));
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--){
        cin>>n>>s;
        for(int i=1;i<=n;i++){
            cin>>a[i];f[i]=a[i]+f[i-1];
        }
        int mxv=0,pos=0;
        for(int i=0;i<=n;i++){
            int cur=check(i);
            if(mxv<cur){
                pos=i;
                mxv=cur;
            }
        }
        cout<<pos<<endl;
    }

    return 0;
}