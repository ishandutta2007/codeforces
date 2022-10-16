#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char s[200005];
int t,n,l,r,sum[200005][26];
int main(){
    scanf("%s",s+1);
    n=strlen(s+1);
    for (int i=1;i<=n;i++){
        for (int j=0;j<26;j++)sum[i][j]=sum[i-1][j];
        sum[i][s[i]-'a']++;
    }
    cin>>t;
    while(t--){
        scanf("%d%d",&l,&r);
        int cnt=0;
        for (int i=0;i<26;i++)
            if (sum[r][i]-sum[l-1][i]!=0)cnt++;
        if (l==r){
            cout<<"Yes"<<endl;
            continue;
        }
        if (cnt>2)cout<<"Yes"<<endl;
        if (cnt==2){
            if (s[r]==s[l])cout<<"No"<<endl;
            else cout<<"Yes"<<endl;
        }
        if (cnt<2)cout<<"No"<<endl;
    }
    return 0;
}