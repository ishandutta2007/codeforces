#include <bits/stdc++.h>
using namespace std;
bool f(char ch){
    if(ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U' || ch=='Y')
        return 1;
    return 0;
}
const int N=100;
char s[N+5];
int n,ans=0,last=-1;
int main(){
    cin.getline(s,N+5);
    n=strlen(s);
    for(int i=0;i<n;i++)
        if(f(s[i])==1){
            ans=max(ans,i-last);
            last=i;
        }
    ans=max(ans,n-last);
    cout<<ans;
    return 0;
}
/**

**/