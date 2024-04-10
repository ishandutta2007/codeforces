#include<bits/stdc++.h>
using namespace std;
int arr[(int)2e5+1][26];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    string s;
    cin>>s;
    int q;
    cin>>q;
    for(int i=0;i<(int)s.size();i++){
        for(int j=0;j<26;j++)arr[i+1][j]=arr[i][j];
        arr[i+1][s[i]-'a']++;
    }
    while(q--){
        int l,r;
        cin>>l>>r;
        int cnt=0;
        for(int i=0;i<26;i++){
            if(arr[r][i]-arr[l-1][i]>0)cnt++;
        }
        bool work=false;
        if(s[r-1]==s[l-1]&&cnt>=3)work=true;
        if(s[r-1]!=s[l-1])work=true;
        if(work||r==l) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}