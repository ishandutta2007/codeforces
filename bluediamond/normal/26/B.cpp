#include <bits/stdc++.h>

using namespace std;

const int N=1000000;
int n;
char s[N+5];
int v[N+5];
int su[N+5];
int l=0,cur=0;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin.getline(s,N+5);
    n=strlen(s);
    for(int i=0;i<n;i++)
        v[i+1]=s[i];
    for(int i=n;i>=1;i--){
        su[i]=su[i+1];
        if(v[i]==')')
            su[i]++;
    }
    for(int i=1;i<=n;i++){
        if(v[i]=='(' && cur+1<=su[i]){
            l++;
            cur++;
        }
        if(v[i]==')' && cur>=1){
            l++;
            cur--;
        }
    }
    cout<<l<<"\n";
    return 0;
}