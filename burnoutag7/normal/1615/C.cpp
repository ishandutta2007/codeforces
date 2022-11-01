#include<bits/stdc++.h>
using namespace std;

int n;
bool a[100005],b[100005];

void mian(){
    cin>>n;
    int cnta=0;
    for(int i=1;i<=n;i++){
        char c;
        cin>>c;
        a[i]=c=='1';
        cnta+=a[i];
    }
    int cntb=0;
    for(int i=1;i<=n;i++){
        char c;
        cin>>c;
        b[i]=c=='1';
        cntb+=b[i];
    }
    if(!cnta){
        if(!cntb){
            cout<<"0\n";
        }else{
            cout<<"-1\n";
        }
        return;
    }
    int ans=1e9;
    if(cnta==cntb){
        int cost=0;
        for(int i=1;i<=n;i++){
            cost+=a[i]!=b[i];
        }
        ans=min(ans,cost);
    }
    if(cnta+cntb-1==n){
        int cost=0;
        for(int i=1;i<=n;i++){
            cost+=a[i]==b[i];
        }
        ans=min(ans,cost);
    }
    if(ans==1e9)ans=-1;
    cout<<ans<<'\n';
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