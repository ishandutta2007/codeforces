#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define M 1000000007
#define fr first
#define sc second
int main(){
    ios_base::sync_with_stdio(false);
    char s[1005],t[1005];
    cin>>s;
    int l=strlen(s);
    int a=0,b=0;
    int n[l];
    for(int i=0;i<l;i++){
        if(s[i]=='a')a++;
        else b++;
    }
    for(int i=0;i<l;i++){
        if(a-->0)t[i]='a';
        else t[i]='b';
    }
    for(int i=l-1;i>=0;i--){
        if(s[i]!=t[i]){
            n[i]=1;
            for(int j=0;j<=(i/2);j++){
                char k=t[j];
                t[j]=t[i-j];
                t[i-j]=k;
            }
        }
        else n[i]=0;
    }
    for(int i=0;i<l;i++){
        cout<<n[i]<<" ";
    }
}