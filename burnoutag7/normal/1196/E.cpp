#include<bits/stdc++.h>
using namespace std;

int q,b,w;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>q;
    while(q--){
        cin>>b>>w;
        if(b>w*3+1||w>b*3+1){
            cout<<"NO"<<endl;
            continue;
        }
        cout<<"YES"<<endl;
        if(b>w){
            for(int i=10;i<=8+w*2;i+=2){
                cout<<10<<' '<<i<<endl;
                if(b){cout<<10<<' '<<i-1<<endl;b--;}
            }
            for(int i=10;i<=8+w*2;i+=2){
                if(b){cout<<9<<' '<<i<<endl;b--;}
                if(b){cout<<11<<' '<<i<<endl;b--;}
            }
            if(b)cout<<10<<' '<<9+w*2<<endl;
        }else{
            for(int i=9;i<=7+b*2;i+=2){
                cout<<10<<' '<<i<<endl;
                if(w){cout<<10<<' '<<i-1<<endl;w--;}
            }
            for(int i=9;i<=7+b*2;i+=2){
                if(w){cout<<9<<' '<<i<<endl;w--;}
                if(w){cout<<11<<' '<<i<<endl;w--;}
            }
            if(w)cout<<10<<' '<<8+b*2<<endl;
        }
    }

    return 0;
}