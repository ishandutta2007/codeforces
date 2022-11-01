#include<bits/stdc++.h>
using namespace std;

int n,q,p[300005],vot[300005];
long long pre[300005];
char s[300005];
stack<int> t;

void deal(int l,int r){
    int cnt=0,x=l+1;
    while(x!=r){
        cnt++;
        x=p[x]+1;
    }
    if(!vot[l]){
        vot[l]=vot[r]=1;
    }
    if(p[r+1]&&p[r+1]>r){
        vot[r+1]=vot[p[r+1]]=vot[l]+1;
    }
    pre[l]=1+cnt*(cnt+1ll)/2-cnt;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>q>>s+1;
    for(int i=1;i<=n;i++){
        if(s[i]=='(')t.emplace(i);
        else if(!t.empty()){
            p[t.top()]=i;
            p[i]=t.top();
            t.pop();
        }
    }
    for(int i=1;i<=n;i++)if(p[i]>i)deal(i,p[i]);
    for(int i=1;i<=n;i++)pre[i]+=pre[i-1];
    while(q--){
        int l,r;
        cin>>l>>l>>r;
        int cnt=vot[r]-vot[l]+1;
        cout<<pre[r]-pre[l-1]+(cnt+1ll)*cnt/2-cnt<<'\n';
    }

    return 0;
}