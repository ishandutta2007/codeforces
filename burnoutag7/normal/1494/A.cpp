#include<bits/stdc++.h>
using namespace std;

int n;
char s[55];
bool a[55];

bool chk(int msk){
    int lvl=0;
    for(int i=1;i<=n;i++){
        lvl=lvl+(msk>>s[i]-'A'&1)-(msk>>s[i]-'A'&1^1);
        if(lvl<0)return false;
    }
    return lvl==0;
}

void mian(){
    cin>>s+1;
    n=strlen(s+1);
    for(int msk=0;msk<1<<3;msk++){
        if(chk(msk)){
            cout<<"yEs\n";
            return; 
        }
    }
    cout<<"nO\n";
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