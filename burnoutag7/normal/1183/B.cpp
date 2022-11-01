#include<bits/stdc++.h>
using namespace std;

int q,n,k,mx,mn;
int a[105];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>q;
    while(q--){
        cin>>n>>k;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        mn=1e9;mx=0;
        for(int i=1;i<=n;i++){
            mx=max(mx,a[i]);
            mn=min(mn,a[i]);
        }
        if(mx>mn+k+k){
            cout<<-1<<endl;
        }else{
            cout<<mn+k<<endl;
        }
    }

    return 0;
}