#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[300005];
int mn[300005];
int mx[300005];
int tree[600005];
int pos[300005];

void upd(int x,int val){
    for(int i=x;i>=0;i=(i&(i+1))-1){
        tree[i]+=val;
    }
}

int qry(int x){
    int res=0;
    for(int i=x;i<=600000;i|=i+1){
        res+=tree[i];
    }
    return res;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i=0;i<n;i++){
        mn[i]=mx[i]=i;
        pos[i]=n-i-1;
        upd(i,1);
    }
    for(int i=0;i<m;i++){
        cin>>a[i];a[i]--;
        mn[a[i]]=0;
        mx[a[i]]=max(mx[a[i]],qry(pos[a[i]]+1));
        upd(pos[a[i]],-1);
        pos[a[i]]=i+n;
        upd(pos[a[i]],1);
    }
    for(int i=0;i<n;i++){
        mx[i]=max(mx[i],qry(pos[i]+1));
        cout<<mn[i]+1<<' '<<mx[i]+1<<endl;
    }

    return 0;
}