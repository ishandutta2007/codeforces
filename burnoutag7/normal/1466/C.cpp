#include<bits/stdc++.h>
using namespace std;

int n,ans;
char s[100005];

bool wkchk(const int& pos){
    for(int i=max(1,pos-2);i<pos;i++)if(s[i]==s[pos])return false;
    return true;
}

bool check(const int& pos){
    for(int i=max(1,pos-2);i<=min(n,pos+2);i++)if(i!=pos&&s[i]==s[pos])return false;
    return true;
}

void mian(){
    cin>>s+1;
    n=strlen(s+1);
    ans=0;
    for(int i=1;i<=n;i++){
        if(!wkchk(i)){
            s[i]='a';
            while(!check(i))s[i]++;
            ans++;
        }
    }
    cout<<ans<<'\n';
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