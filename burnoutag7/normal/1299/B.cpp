#include<bits/stdc++.h>
using namespace std;

int n;
int x[200005];
int y[200005];

pair<int,int> diff(int a,int b){
    return make_pair(x[a]-x[b],y[a]-y[b]);
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x[i]>>y[i];
        x[i+n]=x[i];
        y[i+n]=y[i];
    }
    if(n&1){
        cout<<"NO"<<endl;
        return 0;
    }
    bool fl=true;
    for(int i=0;i<n;i++){
        if(diff(i,i+(n>>1)+1)!=diff(i+1,i+(n>>1))){
            fl=false;
            break;
        }
    }
    if(fl){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }

    return 0;
}