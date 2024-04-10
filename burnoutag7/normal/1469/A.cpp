#include<bits/stdc++.h>
using namespace std;

void mian(){
    string s;
    int i[3]={0},f=0,iv=0;
    cin>>s;
    for(char& c:s){
        if(c=='('||c==')'){
            if(c==')'&&!f)iv=1;
            f++;
        }else i[f]++;
    }
    if(((i[0]&1)^(i[1]&1)^(i[2]&1))||iv&&!(i[0]&&i[2]))cout<<"NO\n";
    else cout<<"YES\n";
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