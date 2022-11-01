#include<bits/stdc++.h>
using namespace std;

int n,s[32];

void mian(){
    cin>>n;
    memset(s,0,sizeof(s));
    for(int i=0;i<n;i++){
        int v=0;
        for(int j=0;j<5;j++){
            int t;
            cin>>t;
            v=v<<1|t;
        }
        s[v]++;
    }
    for(int i=0;i<5;i++){
        for(int j=i+1;j<5;j++){
            int c[4]={0};
            for(int k=0;k<32;k++){
                c[(k>>i&1)<<1|k>>j&1]+=s[k];
            }
            if(c[0])continue;
            if(min(c[1],c[2])+c[3]>=max(c[1],c[2])){
                cout<<"YES\n";
                return;
            }
        }
    }
    cout<<"NO\n";
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