#include<bits/stdc++.h>
using namespace std;

int n,k,p,ans;
char s[500005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k>>s;
    ans=n;
    for(int i=1;i<n;i++){
        if(s[i]==s[p])p++;
        else if(s[i]<s[p])p=0;
        else{
            ans=i-p;
            break;
        }
    }
    ans=min(ans,n-p);
    for(int i=0;i<k;i++)cout<<s[i%ans];

    return 0;
}