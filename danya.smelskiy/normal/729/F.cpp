#include <bits/stdc++.h>
using namespace std;


int n;
int s[4005];
bool used[4005][160][80][2];
int ans[4005][160][80][2];
inline int MAX(int x,int y){
    return (x<y ? y : x);
}
int solve(int l,int r,int x,int y){
    if (r-l+1<x) return 0;
    if (r-l+1==x) return s[r]-s[l-1];
    if (used[l][n-r-l+x][x][y]) return ans[l][n-r-l+x][x][y];
    int res;
    if (!y) {
        res=MAX(s[l+x-1]-s[l-1]-solve(l+x,r,x,1),s[l+x]-s[l-1]-solve(l+x+1,r,x+1,1));
    } else {
        res=MAX(s[r]-s[r-x]-solve(l,r-x,x,0),s[r]-s[r-x-1]-solve(l,r-x-1,x+1,0));
    }
    used[l][n-r-l+x][x][y]=true;
    return ans[l][n-r-l+x][x][y]=res;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i){
        int x;
        cin>>x;
        s[i]=s[i-1]+x;
    }
    cout<<solve(1,n,1,0);
}