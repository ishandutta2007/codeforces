#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<map>
#include<set>
#include<queue>
#include<vector>
#include<stack>
using namespace std;
int n,nxt[200010],ans;
char s[200010];
void solve(int l,int r){
    if(l>r) return;
    ans++;
    for(int i=l;i<=r;i=nxt[i]+1){
        solve(i+1,nxt[i]-1);
    }
}
void solve(){
    scanf("%d %s",&n,s+1);n*=2;
    stack<int> st;
    for(int i=1;i<=n;i++) nxt[i]=0;
    for(int i=1;i<=n;i++){
        if(s[i]=='(') st.push(i);
        else{nxt[st.top()]=i;st.pop();}
    }ans=0;solve(1,n);
    printf("%d\n",ans);
}
int main(){int T;
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}