#include<bits/stdc++.h>
using namespace std;

int n,a[2005],p1,fa[2005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1;i<=n*2;i++){
        cin>>a[i];
        if(a[i]==1)p1=i;
    }
    queue<int> q;
    q.emplace(p1);
    fa[p1]=-1;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        if(!fa[(x-1^1)+1]){
            fa[(x-1^1)+1]=x;
            q.emplace((x-1^1)+1);
        }
        if(!fa[x<=n?x+n:x-n]){
            fa[x<=n?x+n:x-n]=x;
            q.emplace(x<=n?x+n:x-n);
        }
    }
    vector<int> v;
    for(int x=1;fa[x]!=-1;x=fa[x]){
        v.emplace_back(abs(x-fa[x])==1?1:2);
    }
    reverse(v.begin(),v.end());
    for(int op:v)if(op==1){
        for(int i=1;i<n*2;i+=2)swap(a[i],a[i+1]);
    }else{
        for(int i=1;i<=n;i++)swap(a[i],a[i+n]);
    }
    for(int i=1;i<=n*2;i++)if(a[i]!=i){
        cout<<-1;
        return 0;
    }
    cout<<v.size();

    return 0;
}