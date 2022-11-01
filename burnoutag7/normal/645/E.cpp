#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod=1000000007;

int n,k;
string s;
int last[256];
ll dp[2000006];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    cin>>s;
    memset(last,-1,sizeof(last));
    for(int i=1;i<=s.size();i++){
        if(last[s[i-1]]==-1){
            dp[i]=(dp[i-1]*2+1)%mod;
            last[s[i-1]]=i;
        }else{
            dp[i]=(dp[i-1]*2-dp[last[s[i-1]]-1]+mod)%mod;
            last[s[i-1]]=i;
        }
    }
    int dst=s.size()+n;
    for(int i=s.size()+1;i<=dst;i++){
        char res;
        int cur=1e9;
        for(char c='a';c<='a'+k-1;c++){
            if(last[c]<cur){
                cur=last[c];
                res=c;
            }
        }
        if(last[res]==-1){
            dp[i]=(dp[i-1]*2+1)%mod;
            last[res]=i;
        }else{
            dp[i]=(dp[i-1]*2-dp[last[res]-1]+mod)%mod;
            last[res]=i;
        }
        s+=res;
    }
    cout<<(dp[dst]+1)%mod<<endl;
    //cout<<s<<endl;

    return 0;
}