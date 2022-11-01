#include<bits/stdc++.h>
using namespace std;

int n,m,a[300005],b[300005],c[300005],d[300005];
pair<pair<int,int>,int> v[300005];

void mian(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>v[i].first.first;
    for(int i=1;i<=n;i++){
        char dir;
        cin>>dir;
        v[i].first.second=dir=='R';
        v[i].second=i;
    }
    sort(v+1,v+n+1);
    for(int i=1;i<=n;i++)tie(a[i],b[i])=v[i].first,d[v[i].second]=i;
    stack<int> s[2];
    for(int i=1;i<=n;i++){
        stack<int> &cs=s[a[i]&1];
        if(b[i]){
            cs.emplace(i);
        }else{
            if(cs.empty())cs.emplace(-i);
            else{
                int p=cs.top();
                cs.pop();
                if(p<0){
                    p=-p;
                    c[p]=c[i]=a[i]+a[p]>>1;
                }else{
                    c[p]=c[i]=a[i]-a[p]>>1;
                }
            }
        }
    }
    for(int i=0;i<2;i++){
        stack<int> &cs=s[i];
        while(cs.size()>1){
            int x=cs.top();cs.pop();
            int y=cs.top();cs.pop();
            if(y>0)c[x]=c[y]=m*2-a[x]-a[y]>>1;
            else{
                y=-y;
                c[x]=c[y]=m*2-a[x]+a[y]>>1;
            }
        }
        if(!cs.empty())c[abs(cs.top())]=-1;
    }
    for(int i=1;i<=n;i++)cout<<c[d[i]]<<' ';
    cout<<'\n';
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--)mian();

    return 0;
}