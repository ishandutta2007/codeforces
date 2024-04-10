#include<bits/stdc++.h>
using namespace std;

int n,len;
int f[26];
bool gu[26];
char s[55];
bool u[26];

int find(int x){
    if(f[x]==x)return x;
    else return f[x]=find(f[x]);
}

void unite(int x,int y){
    x=find(x);
    y=find(y);
    f[x]=y;
}

int main(){

    scanf("%d",&n);n++;
    for(int i=0;i<26;i++)f[i]=i;
    while(--n){
        scanf("%s",s);
        len=strlen(s);
        memset(u,0,sizeof(u));
        for(int i=0;i<len;i++){
            for(int j=0;j<26;j++){
                if(u[j])unite(s[i]-'a',j);
            }
            u[s[i]-'a']=true;
            gu[s[i]-'a']=true;
        }
    }
    int ans=0;
    for(int i=0;i<26;i++){
        bool fl=gu[i];
        for(int j=0;j<i;j++){
            if(find(i)==find(j)){
                fl=false;
                break;
            }
        }
        ans+=fl;
    }
    cout<<ans<<endl;

    return 0;
}