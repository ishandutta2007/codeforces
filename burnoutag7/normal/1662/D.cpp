#include<bits/stdc++.h>
using namespace std;

void iter(string &s){
    int i;
    if((i=s.find("AA"))!=s.npos){
        s.erase(s.begin()+i,s.begin()+i+2);
    }else if((i=s.find("CC"))!=s.npos){
        s.erase(s.begin()+i,s.begin()+i+2);
    }else return;
    iter(s);
}

void mian(){
    string u,v;
    cin>>u>>v;
    string s,t;
    int ub=0,vb=0;
    for(char c:u){
        if(c!='B')s+=c;
        else ub^=1;
    }
    for(char c:v){
        if(c!='B')t+=c;
        else vb^=1;
    }
    if(ub!=vb){
        cout<<"NO\n";
        return;
    }
    iter(s);
    iter(t);
    cout<<(s==t?"YES\n":"NO\n");
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