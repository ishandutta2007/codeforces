#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod=1145141919;
const ll p=810;

int n,m;
char s[200005];
ll pw[200005];
ll h[200005][30];

ll geth(int st,int ed,int id){
    return (h[ed][id]-h[st-1][id]*pw[ed-st+1]%mod+mod)%mod;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    cin>>s+1;
    pw[0]=1;
    for(int i=1;i<=200000;i++){
        pw[i]=pw[i-1]*p%mod;
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<26;j++){
            h[i][j]=(h[i-1][j]*p+1+(j+'a'==s[i]))%mod;
        }
    }
    while(m--){
        int x,y,len;
        cin>>x>>y>>len;
        set<ll> sx,sy;
        for(int i=0;i<26;i++){
            sx.insert(geth(x,x+len-1,i));
            sy.insert(geth(y,y+len-1,i));
        }
        if(sx==sy){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }

    return 0;
}