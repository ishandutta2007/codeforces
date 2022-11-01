#include<bits/stdc++.h>
using namespace std;

int n;
char s[200005],t1[200005],t2[200005];
int nxt[200005];

bool parse(char *str){
    int cnt=0;
    for(int i=1;i<=n;i++){
        cnt+=(str[i]=='(')-(str[i]==')');
        if(cnt<0){
            return false;
        }
    }
    if(cnt){
        return false;
    }
    return true;
}

void mian(){
    cin>>n>>s+1;
    int f0=-1,l0=-1;
    for(int i=1,p=0;i<=n;i++)if(s[i]=='0'){
        t1[i]='('+p;
        t2[i]=')'-p;
        p^=1;
        if(f0==-1)f0=i;
        l0=i;
    }
    if(f0!=-1){
        t1[f0-1]=t2[f0-1]='(';
        t1[l0+1]=t2[l0+1]=')';
    }
    for(int i=1,p=0;i<=n;i++)if(s[i]=='1'&&i!=f0-1&&i!=l0+1){
        t1[i]='('+p;
        t2[i]='('+p;
        p^=1;
    }
    if(parse(t1)&&parse(t2)){
        cout<<"YES\n";
        t1[n+1]=0;
        cout<<t1+1<<'\n';
        t2[n+1]=0;
        cout<<t2+1<<'\n';
    }else{
        cout<<"NO\n";
    }
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