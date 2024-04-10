#include<bits/stdc++.h>
using namespace std;

int q,n;
int p[405];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>q;
    while(q--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>p[i];
            p[i]--;
            p[i+n]=p[i];
        }
        bool cw=true;
        bool ccw=true;
        for(int i=1;i<=n;i++){
            if((p[i]+1)%n!=p[i+1]){
                cw=false;
            }
            if(p[i]!=(p[i+1]+1)%n){
                ccw=false;
            }
        }
        if(cw||ccw){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }

    return 0;
}