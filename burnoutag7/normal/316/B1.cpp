#include<bits/stdc++.h>
using namespace std;

int a[10005];
int n,x;
int sz[10005];
set<int> t;
int cnt,pos;

void dfs(int x,int cur){
    if(x>cnt){
        t.insert(cur);
        return;
    }
    dfs(x+1,cur+sz[x]);
    dfs(x+1,cur);
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>x;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int cur=i;
        while(a[cur]!=0){
            cur=a[cur];
        }
        sz[cur]++;
    }
    int cur=x;
    while(a[cur]!=0){
        cur=a[cur];
        pos++;
    }
    sz[cur]=0;
    for(int i=1;i<=n;i++){
        if(sz[i]){
            sz[++cnt]=sz[i];
        }
    }
    sort(sz+1,sz+cnt+1);
    dfs(1,0);

    for(set<int>::iterator it=t.begin();it!=t.end();it++){
        cout<<*it+pos+1<<endl;
    }

    return 0;
}