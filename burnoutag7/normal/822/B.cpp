#include<bits/stdc++.h>
using namespace std;

string s,t;
int n,m;
int ans,pos;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    cin>>s>>t;
    int ans=1e9;
    for(int i=0;i+n-1<m;i++){
        int cnt=0;
        for(int j=0;j<n;j++){
            cnt+=t[i+j]!=s[j];
        }
        if(ans>cnt){
            ans=cnt;
            pos=i;
        }
    }
    cout<<ans<<endl;
    for(int i=0;i<n;i++){
        if(s[i]!=t[i+pos])cout<<i+1<<' ';
    }

    return 0;
}