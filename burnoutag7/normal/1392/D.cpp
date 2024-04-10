#include<bits/stdc++.h>
using namespace std;

int n;
string s;
int atk[200005],def[200005],ic[200005],ccnt,bad[200005];

void dfs(int x){
    ic[x]=ccnt;
    if(!ic[atk[x]])dfs(atk[x]);
    bad[ccnt]+=atk[atk[x]]!=x;
}

void mian(){
    cin>>n>>s;
    ccnt=0;
    memset(def,0,n<<2);
    memset(ic,0,n<<2);
    memset(bad+1,0,n<<2);
    for(int i=0;i<n;i++){
        if(s[i]=='R')atk[i]=(i+1)%n;
        else atk[i]=(i-1+n)%n;
        def[atk[i]]++;
    }
    ccnt=0;
    int ans=0;
    for(int i=0;i<n;i++){
        if(!def[i]){
            ccnt++;
            dfs(i);
            ans+=(bad[ccnt]+1)/3;
        }
    }
    for(int i=0;i<n;i++){
        if(!ic[i]){
            ccnt++;
            dfs(i);
            ans+=(bad[ccnt]+2)/3;
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