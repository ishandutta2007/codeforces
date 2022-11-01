#include<bits/stdc++.h>
using namespace std;

int n,k,f[505];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    memset(f,-1,sizeof(f));
    f[0]=0;
    queue<int> q;
    q.emplace(0);
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(int i=max(x+k-n,0);i<=min(k,x);i++){
            int y=x+k-2*i;
            if(f[y]==-1){
                f[y]=i;
                q.emplace(y);
            }
        }
    }
    if(f[n]==-1){
        cout<<-1;
        return 0;
    }
    queue<int> a,b;
    for(int i=1;i<=n;i++)a.emplace(i);
    vector<int> v;
    {
        int x=n;
        while(x){
            v.emplace_back(f[x]);
            x+=2*f[x]-k;
        }
    }
    reverse(v.begin(),v.end());
    int ans=0;
    for(int x:v){
        cout<<"? ";
        for(int i=0;i<k-x;i++){
            cout<<a.front()<<' ';
            b.emplace(a.front());
            a.pop();
        }
        for(int i=0;i<x;i++){
            cout<<b.front()<<' ';
            a.emplace(b.front());
            b.pop();
        }
        cout<<endl;
        int cur;
        cin>>cur;
        ans^=cur;
    }
    cout<<"! "<<ans;

    return 0;
}