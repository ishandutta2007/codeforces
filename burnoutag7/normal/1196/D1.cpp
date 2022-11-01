#include<bits/stdc++.h>
using namespace std;

int q,n,k,ans;
string s,pat;
int f[200005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    pat="RGB";
    cin>>q;
    while(q--){
        cin>>n>>k;
        cin>>s;
        ans=1e9;
        memset(f,0,sizeof(f));
        for(int i=0;i<s.size();i++){
            f[i+1]=f[i];
            f[i+1]+=s[i]!=pat[i%3];
        }
        for(int i=1;i+k-1<=s.size();i++){
            ans=min(ans,f[i+k-1]-f[i-1]);
        }
        memset(f,0,sizeof(f));
        for(int i=0;i<s.size();i++){
            f[i+1]=f[i];
            f[i+1]+=s[i]!=pat[(i+1)%3];
        }
        for(int i=1;i+k-1<=s.size();i++){
            ans=min(ans,f[i+k-1]-f[i-1]);
        }
        memset(f,0,sizeof(f));
        for(int i=0;i<s.size();i++){
            f[i+1]=f[i];
            f[i+1]+=s[i]!=pat[(i+2)%3];
        }
        for(int i=1;i+k-1<=s.size();i++){
            ans=min(ans,f[i+k-1]-f[i-1]);
        }
        cout<<ans<<endl;
    }

    return 0;
}