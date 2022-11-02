#include<bits/stdc++.h>
using namespace std;

int q;
string s,t,p,nd;
bool u[105];

void solve(){
    nd.clear();
    memset(u,0,sizeof(u));
    int pos=0;
    for(int i=0;i<s.size();i++){
        bool f=false;
        for(int j=pos;j<t.size();j++){
            if(t[j]==s[i]){
                u[j]=true;
                pos=j+1;
                f=true;
                break;
            }
        }
        if(!f){
            cout<<"nO"<<endl;
            return;
        }
    }
    for(int i=0;i<t.size();i++){
        if(!u[i])nd+=t[i];
    }
    sort(nd.begin(),nd.end());
    //cout<<nd<<endl;
    sort(p.begin(),p.end());
    pos=0;
    for(int i=0;i<nd.size();i++){
        bool f=false;
        for(int j=pos;j<p.size();j++){
            if(p[j]==nd[i]){
                pos=j+1;
                f=true;
                break;
            }
        }
        if(!f){
            cout<<"nO"<<endl;
            return;
        }
    }
    cout<<"yEs"<<endl;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>q;
    while(q--){
        cin>>s>>t>>p;
        solve();
    }

    return 0;
}