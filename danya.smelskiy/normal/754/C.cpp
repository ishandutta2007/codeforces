#include <bits/stdc++.h>
using namespace std;

int n,t;
map<string,int> num;
int m;
string s;
bool dp[1005][1005];
string ss[1005],sk[1005];
bool used[105][105];
int name[105];
int pred[105][105];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>t;
    for (int zz=1;zz<=t;++zz) {
        cin>>n;
        num.clear();
        for (int i=1;i<=n;++i) {
            cin>>s;
            num[s]=i;
            sk[i]=s;
        }
        cin>>m;
        getline(cin,s);
        for (int i=1;i<=m;++i) {
            getline(cin,s);
            ss[i]=s;
            string nm="";
            int pos=0;
            while (s[pos]!=':') nm+=s[pos++];
            for (int j=1;j<=n;++j)
                used[i][j]=false;
            if (nm=="?") name[i]=0;
            else name[i]=num[nm];
            ++pos;
            string last="";
            s+=" ";
            for (int j=pos;j<s.size();++j){
                if (s[j]==',' || s[j]=='.' || s[j]==' ' || s[j]=='?' || s[j]=='!') {
                    if (num[last]) used[i][num[last]]=true;
                    last="";
                }else last+=s[j];
            }
        }
        for (int i=0;i<=m;++i)
            for (int j=0;j<=n;++j)
                dp[i][j]=false;
        dp[0][0]=true;
        for (int i=1;i<=m;++i) {
            if (name[i]) {
                for (int j=0;j<=n;++j)
                if (j!=name[i] && dp[i-1][j]) {
                    dp[i][name[i]]=true;
                    pred[i][name[i]]=j;
                    break;
                }
                continue;
            } else {
                for (int j=1;j<=n;++j)
                    if (used[i][j]==false)
                    for (int k=0;k<=n;++k)
                if (j!=k && dp[i-1][k]) {
                    dp[i][j]=true;
                    pred[i][j]=k;
                }
            }
        }
        int pos=0;
        for (int i=1;i<=n;++i)
        if (dp[m][i]) {
            pos=i;
            break;
        }
        if (!pos) {
            cout<<"Impossible"<<'\n';
            continue;
        }
        vector<string> ans;
        for (int i=m;i>0;--i) {
            if (name[i]) {
                ans.push_back(ss[i]);
                pos=pred[i][pos];
                continue;
            } else {
                string s1=sk[pos];
                for (int j=1;j<ss[i].size();++j)
                    s1+=ss[i][j];
                ans.push_back(s1);
                pos=pred[i][pos];
            }
        }
        for (int i=ans.size()-1;i>=0;--i)
            cout<<ans[i]<<'\n';
    }
}