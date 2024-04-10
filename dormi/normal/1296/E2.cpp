#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
set<int> use[26];
int col[(int)2e5+1];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    string a;
    cin>>a;
    for(int i=0;i<26;i++)for(int j=1;j<=26;j++)use[i].insert(j);
    int ans=0;
    for(int i=0;i<n;i++){
        int c=*use[a[i]-'a'].begin();
        ans=max(ans,c);
        col[i]=c;
        for(int j=0;j<a[i]-'a';j++)use[j].erase(c);
    }
    printf("%d\n",ans);
    for(int i=0;i<n;i++)printf("%d ",col[i]);
    return 0;
}