#include <bits/stdc++.h>
#define rep(i,l,r) for (int i=l,i##end=r;i<=i##end;++i)
#define per(i,r,l) for (int i=r,i##end=l;i>=i##end;--i)
#define sit set<int>::iterator
#define ll long long
using namespace std;
const int N=1e3+3,INF=1e9;
vector<int> ans[N];
bool del[N];
int a[N];
int main(){
    string s; cin>>s;
    int n=s.length();
    rep(i,1,n) a[i]=s[i-1]=='(';
    int c=0;
    while (true){
        int l=1,r=n; bool t=false;
        while (l<r){
            if (del[l]||!a[l]) ++l;
            else if (del[r]||a[r]) --r;
            else{
                t=true; del[l]=del[r]=true;
                ans[c+1].push_back(l);
                ans[c+1].push_back(r);
                ++l,--r;
            }
        }
        if (!t) break;
        ++c;
    }
    cout<<c<<endl;
    rep(i,1,c){
        cout<<ans[i].size()<<endl;
        sort(ans[i].begin(),ans[i].end());
        rep(j,0,ans[i].size()-1) printf("%d ",ans[i][j]);
        cout<<endl;
    }
}