#include<bits/stdc++.h>
using namespace std;

int n,m;
char s[100005],t[100005];

void mian(){
    cin>>s+1>>t+1;
    n=strlen(s+1);
    m=strlen(t+1);
    reverse(s+1,s+1+n);
    reverse(t+1,t+1+m);
    int p=0;
    for(int i=1;i<=m;i++){
        while(p<n&&s[p+1]!=t[i])p+=2;
        p++;
        if(p>n){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
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