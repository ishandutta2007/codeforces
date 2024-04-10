#include<bits/stdc++.h>
using namespace std;

int win(string s,int x){
    for(int i=0;i<s.size();i++){
        if(s[i]=='?')s[i]=(i&1)==x?'1':'0';
    }
    int kicks[2]={5,5},goals[2]={0,0};
    for(int i=0;i<s.size();i++){
        kicks[i&1]--;
        goals[i&1]+=s[i]=='1';
        if(goals[i&1]-goals[i&1^1]>kicks[i&1^1])return i+1;
        if(goals[i&1^1]-goals[i&1]>kicks[i&1])return i+1;
    }
    return 10;
}

void mian(){
    string s;
    cin>>s;
    cout<<min(win(s,0),win(s,1))<<'\n';
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