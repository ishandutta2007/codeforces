#include<bits/stdc++.h>
using namespace std;

int n,ch[26];
char s[100005];

void mian(){
    cin>>s+1;
    n=strlen(s+1);
    memset(ch,0,sizeof(ch));
    for(int i=1;i<=n;i++)ch[s[i]-'a']++;
    memset(s+1,0,n);
    for(int i=0;i<26;i++)if(ch[i]==1){
        s[1]=i+'a';
        ch[i]=0;
        int p=1;
        for(int j=0;j<26;j++){
            while(ch[j]--){
                s[++p]=j+'a';
            }
        }
        s[n+1]=0;
        cout<<s+1<<'\n';
        return;
    }
    int mp=0;
    while(!ch[mp])mp++;
    int dfc=0;
    for(int i=0;i<26;i++)dfc+=(bool)ch[i];
    if(2+(n-2)/2>=ch[mp]){
        s[1]=s[2]=mp+'a';
        ch[mp]-=2;
        for(int i=3;i<=n;i++){
            for(int j=mp+1;j<26;j++)if(ch[j]){
                s[i]=j+'a';
                ch[j]--;
                if(ch[mp]){
                    s[i+1]=mp+'a';
                    ch[mp]--;
                    i++;
                }
                break;
            }
        }
    }else if(ch[mp]!=n){
        if(dfc>=3){
            s[1]=mp+'a';
            ch[mp]--;
            int rb;
            for(int i=3;ch[mp]--;i++)s[i]=mp+'a',rb=i;
            int smp;
            for(int j=mp+1;j<26;j++)if(ch[j]){
                s[2]=j+'a';
                ch[j]--;
                smp=j;
                break;
            }
            for(int j=smp+1;j<26;j++)if(ch[j]){
                s[rb+1]=j+'a';
                rb++;
                ch[j]--;
                break;
            }
            for(int i=rb+1;i<=n;i++){
                for(int j=mp+1;j<26;j++)if(ch[j]){
                    s[i]=j+'a';
                    ch[j]--;
                    break;
                }
            }
        }else{
            int smp;
            for(smp=mp+1;!ch[smp];smp++);
            s[1]=mp+'a';
            ch[mp]--;
            for(int i=2;i<=n;i++){
                if(ch[smp]){
                    s[i]=smp+'a';
                    ch[smp]--;
                }else s[i]=mp+'a';
            }
        }
    }else{
        for(int i=1;i<=n;i++)s[i]=mp+'a';
    }
    s[n+1]=0;
    cout<<s+1<<'\n';
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