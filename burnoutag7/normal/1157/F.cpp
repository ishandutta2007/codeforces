#include<bits/stdc++.h>
using namespace std;

const int V=2e5;

int n,c[200005];
vector<int> ans,cur;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        c[a]++;
    }
    for(int i=1;i<=V;i++){
        cur.clear();
        for(int j=0;j<c[i];j++){
            cur.push_back(i);
        }
        if(cur.size()>ans.size())ans=cur;
    }
    for(int l=1;l<V;l++)if(c[l]&&c[l+1]){
        int r=l+1;
        while(c[r]>=2&&c[r+1])r++;
        cur.clear();
        cur.emplace_back(l);
        for(int i=l;i<=r;i++)while(--c[i])cur.emplace_back(i);
        for(int i=r;i>l;i--)cur.emplace_back(i);
        if(cur.size()>ans.size())ans=cur;
        if(c[r+1])c[r]=1;
        l=r-1;
    }
    cout<<ans.size()<<'\n';
    for(int x:ans)cout<<x<<' ';

    return 0;
}