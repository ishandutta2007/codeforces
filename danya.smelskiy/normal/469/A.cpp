#include <bits/stdc++.h>
using namespace std;
int n,x,y,ans;
int used[10001];
int main(){
    cin>>n;
    cin>>x;
    for (int i=1;i<=x;++i){
        cin>>y;
        if (used[y]==false) {used[y]=true; ++ans;}
    }
    cin>>x;
    for (int i=1;i<=x;++i){
        cin>>y;
        if (used[y]==false) {used[y]=true; ++ans;}
    }
    if (ans==n) cout<<"I become the guy.";
    else cout<<"Oh, my keyboard!";
}