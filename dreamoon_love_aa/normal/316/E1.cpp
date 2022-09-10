#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<bitset>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#define pb push_back
using namespace std;
int a[200010];
long long fi[200010];
#define MOD 1000000000
int main(){
    int i,j,k,n,m;
    fi[0]=fi[1]=1;
    for(i=2;i<=200000;i++){
        fi[i]=fi[i-1]+fi[i-2];
        if(fi[i]>=MOD)fi[i]-=MOD;
    }
    cin>>n>>m;
    for(i=1;i<=n;i++)cin>>a[i];
    while(m--){
        int tt;
        cin>>tt;
        if(tt==1){
            int x,v;
            cin>>x>>v;
            a[x]=v;
        }
        else if(tt==2){
            int l,r;
            cin>>l>>r;
            long long res=0;
            for(i=0;i<=r-l;i++){
                res+=fi[i]*a[l+i]%MOD;
                res%=MOD;
            }
            cout<<res<<endl;
        }
        else{
            int l,r,d;
            cin>>l>>r>>d;
            for(i=l;i<=r;i++){
                a[i]+=d;
                a[i]%=MOD;
            }
        }
    }
    return 0;
}