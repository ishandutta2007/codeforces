#include<bits/stdc++.h>
using namespace std;

char s[200005];
int nxt[200005][26],hav[26],n;

void mian(){
    cin>>s+1;
    n=strlen(s+1);
    memset(nxt[n+1],-1,sizeof(nxt[0]));
    for(int i=n;i>=1;i--){
        memcpy(nxt[i],nxt[i+1],sizeof(nxt[0]));
        nxt[i][s[i]-'a']=i;
    }
    memcpy(hav,nxt[1],sizeof(hav));
    int cp=1;
    while(*max_element(hav,hav+26)!=-1){
        for(char c='z';c>='a';c--)if(hav[c-'a']!=-1){
            bool f=true;
            int np=nxt[cp][c-'a'];
            if(np==-1)continue;
            for(int i=0;i<26;i++)if(hav[i]>nxt[np][i])f=false;
            if(f){
                cout<<c;
                cp=np+1;
                hav[c-'a']=-1;
                break;
            }
        }
    }
    cout<<'\n';
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