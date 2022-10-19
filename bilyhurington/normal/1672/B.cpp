#include<bits/stdc++.h>
using namespace std;
int T,n,m;
void solve(){
    string S;
    cin>>S;
    int x=0;
    for(auto c:S){
        if(c=='B') x--;
        else x++;
        if(x<0){
            puts("NO");
            return;
        }
    }
    if(S.back()=='A') puts("NO");
    else puts("YES");
}
int main(){
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}