#include<bits/stdc++.h>
using namespace std;

int n,cs[26],ct[26];
char s[200005],t[200005];

void mian(){
    memset(cs,0,104);
    memset(ct,0,104);
    cin>>n>>s+1>>t+1;
    for(int i=1;i<=n;i++){
        cs[s[i]-'a']++;
        ct[t[i]-'a']++;
    }
    if(memcmp(cs,ct,104)){
        cout<<"NO\n";
        return;
    }
    if(*max_element(cs,cs+26)>1){
        cout<<"YES\n";
        return;
    }
    int c=0;
    for(int i=2;i<=n;i++){
        for(int j=1;j<i;j++){
            c+=(s[j]>s[i])-(t[j]>t[i]);
        }
    }
    cout<<(c%2?"NO\n":"YES\n");
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