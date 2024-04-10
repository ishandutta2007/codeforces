#include<bits/stdc++.h>

using namespace std;

const int maxn=105;

char s[maxn];
int n;

int main(){
    ios::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--){
        cin>>(s+1);
        n=strlen(s+1);
        sort(s+1,s+1+n,[](char a,char b){return (((a&1)==(b&1))?(a<b):(b&1));});
        bool ok=1;
        for(int i=2;i<=n;i++) if(s[i]==s[i-1]+1||s[i-1]==s[i]+1) ok=0;
        if(ok){
            cout<<(s+1)<<endl;
            continue;
        }
        sort(s+1,s+1+n,[](char a,char b){return (((a&1)==(b&1))?(a<b):(a&1));});
        ok=1;
        for(int i=2;i<=n;i++) if(s[i]==s[i-1]+1||s[i-1]==s[i]+1) ok=0;
        if(ok){
            cout<<(s+1)<<endl;
            continue;
        }
        cout<<"No answer\n";
    }
    return 0;
}