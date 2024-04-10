#include<bits/stdc++.h>
using namespace std;

int n,p0[200005],s1[200005];
char s[200005];

void mian(){
    cin>>s+1;
    n=strlen(s+1);
    if(s[1]=='0'||s[n]=='1'){
        cout<<"1\n";
        return;
    }
    for(int i=1;i<=n;i++)p0[i]=p0[i-1]||s[i]=='0';
    s1[n+1]=0;
    for(int i=n;i>=1;i--)s1[i]=s1[i+1]||s[i]=='1';
    int th=0;
    for(int i=1;i<=n;i++)if(s[i]=='0'&&s1[i])th++;
    for(int i=1;i<=n;i++)if(s[i]=='1'&&p0[i])th++;
    if(th){
        cout<<th<<'\n';
        return;
    }
    int l=1;
    while(s1[l+1])l++;
    int r=n;
    while(p0[r-1])r--;
    cout<<r-l+1<<'\n';
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