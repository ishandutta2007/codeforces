#include<bits/stdc++.h>
using namespace std;

int n;
int a[105];
int ans;

int func(int in,int out){
    if(in==1&&out==2)return 3;
    if(in==1&&out==3)return 4;
    if(in==2&&out==1)return 3;
    if(in==3&&out==1)return 4;
    return -1;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=2;i<=n;i++){
        if(a[i]+a[i-1]==5){
            cout<<"Infinite"<<endl;
            return 0;
        }else{
            ans+=func(a[i],a[i-1]);
            if(a[i]==2&&a[i-1]==1&&a[i-2]==3)ans--;
        }
    }
    cout<<"Finite"<<endl;
    cout<<ans<<endl;

    return 0;
}