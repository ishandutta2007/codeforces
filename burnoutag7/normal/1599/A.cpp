#include<bits/stdc++.h>
using namespace std;

char rev(char c){
    return c=='L'?'R':'L';
}

int n,a[200005];
char s[200005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    cin>>s+1;
    sort(a+1,a+n+1);
    int revc=0;
    for(int i=1;i<=n;i++)revc+=s[i]!=s[i-1];
    reverse(a+1,a+n-revc+1);
    char d=s[1];
    int crit=n-revc,non=0;
    for(int i=1;i<=n;i++)if(s[i]!=s[i-1]){
        cout<<a[++crit]<<' '<<s[i]<<'\n';
    }else{
        d=rev(d);
        cout<<a[++non]<<' '<<d<<'\n';
    }

    return 0;
}