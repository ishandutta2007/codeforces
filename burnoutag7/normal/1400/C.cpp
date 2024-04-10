#include<bits/stdc++.h>
using namespace std;

char s[100005],t[100005];
int n,x;

void mian(){
    cin>>s+1>>x;
    n=strlen(s+1);
    memset(t+1,'1',n);
    for(int i=1;i<=n;i++)if(s[i]=='0'){
        if(i>x)t[i-x]='0';
        if(i+x<=n)t[i+x]='0';
    }
    bool f=true;
    for(int i=1;i<=n;i++)if(s[i]=='1'){
        bool c=false;
        if(i>x)c|=t[i-x]=='1';
        if(i+x<=n)c|=t[i+x]=='1';
        f&=c;
    }
    t[n+1]=0;
    if(f){
        cout<<t+1<<'\n';
    }else{
        cout<<"-1\n";
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