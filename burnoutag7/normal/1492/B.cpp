#include<bits/stdc++.h>
using namespace std;

int n,p[100005],mxp[100005];

void mian(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>p[i];
        if(p[mxp[i-1]]>p[i]){
            mxp[i]=mxp[i-1];
        }else{
            mxp[i]=i;
        }
    }
    int ed=n;
    while(ed){
        int cp=mxp[ed];
        for(int i=cp;i<=ed;i++)cout<<p[i]<<' ';
        ed=cp-1;
    }
    cout<<'\n';
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