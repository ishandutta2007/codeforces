#include<bits/stdc++.h>
using namespace std;

int n,x,m;
int l[105],r[105];
int mn,mx;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--){
        cin>>n>>x>>m;
        mn=mx=x;
        for(int i=0;i<m;i++){
            cin>>l[i]>>r[i];
            if(r[i]>=mn&&l[i]<=mx){
                mn=min(mn,l[i]);
                mx=max(mx,r[i]);
            }
        }
        cout<<mx-mn+1<<endl;
    }

    return 0;
}