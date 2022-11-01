#include<bits/stdc++.h>
using namespace std;

int n,k;
string s;
bool p[26];

void mian(){
    cin>>n>>k;
    cin>>s;
    memset(p,0,sizeof(p));
    for(char c:s){
        if(c!='a'){
            int i=c-'a';
            while(k&&i&&!p[i]){
                p[i--]=1;
                k--;
            }
        }
    }
    for(char &c:s){
        while(p[c-'a'])c--;
    }
    cout<<s<<'\n';
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