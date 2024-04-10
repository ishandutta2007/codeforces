#include<bits/stdc++.h>
using namespace std;

int T,ls,lt;
char s[100005];
char t[100005];
int nxt[100005][26];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>T;
    while(T--){
        cin>>s+1;
        cin>>t+1;
        ls=strlen(s+1);
        lt=strlen(t+1);
        memset(nxt[ls+1],-1,sizeof(nxt[ls+1]));
        for(int i=ls;i>=1;i--){
            memcpy(nxt[i],nxt[i+1],sizeof(nxt[i]));
            nxt[i][s[i]-'a']=i;
        }
        int p=1,ans=1;
        bool fl=true;
        for(int i=1;i<=lt;i++){
            if(nxt[p][t[i]-'a']==-1){
                p=1;
                ans++;
                if(nxt[1][t[i]-'a']==-1){
                    fl=false;
                    break;
                }
            }
            p=nxt[p][t[i]-'a']+1;
        }
        if(!fl){
            cout<<-1<<endl;
        }else{
            cout<<ans<<endl;
        }
    }

    return 0;
}