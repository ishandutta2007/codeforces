#include<bits/stdc++.h>

using namespace std;

const int maxn=105;

int n;
char s[maxn];

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        cin>>(s+1);
        int lp=n+1,rp=n+1;
        for(int i=1;i<=n;i++){
            if(s[i]=='>'){
                lp=i-1;
                break;
            }
        }
        for(int i=n;i>=1;i--){
            if(s[i]=='<'){
                rp=n-i;
                break;
            }
        }
        cout<<min(lp,rp)<<'\n';
    }
    return 0;
}