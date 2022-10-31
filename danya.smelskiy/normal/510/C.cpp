#include <bits/stdc++.h>
using namespace std;

int n;
string s[1000];
vector<int> ans;
bool uu[1000];
vector<int> v[100];
bool used[100];
int depth[200];
void dfs(int x){
    used[x]=true;
    for (int i=0;i<v[x].size();++i){
        int to=v[x][i];
        if (!used[to]) dfs(to);
    }
    ans.push_back(x);
}
int main(){
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>s[i];
    }
    for (int i=1;i<n;++i){
        string ss=s[i];
        string sk=s[i+1];
        if (sk.size()<ss.size()){
            string ssk="";
            for (int j=0;j<sk.size();++j)
                ssk=ssk+ss[j];
            if (ssk==sk) return cout<<"Impossible",0;
        }
        for (int i=0;i<min((int)ss.size(),(int)sk.size());++i){
            int x=ss[i]-'a';
            int y=sk[i]-'a';
            if (x==y) continue;
            uu[x]=true;
            uu[y]=true;
            v[y].push_back(x);
            break;
        }
    }
    for (int i=0;i<26;++i)
        if (!used[i] && uu[i]) dfs(i);
    for (int i=0;i<ans.size();++i){
        depth[ans[i]]=i;
    }
    for (int i=1;i<n;++i){
        string ss=s[i];
        string sk=s[i+1];
        for (int j=0;j<min((int)ss.size(),(int)sk.size());++j){
            int x=ss[j]-'a';
            int y=sk[j]-'a';
            if (x==y) continue;
            if (depth[x]>depth[y]) {
                cout<<"Impossible";
                return 0;
            }
            break;
        }
    }
        //reverse(ans.begin(),ans.end());
    for (int i=0;i<26;++i)
        if (!uu[i]) cout<<char(i+'a');
    for (int i=0;i<ans.size();++i)
        cout<<char(ans[i]+'a');

}