#include <bits/stdc++.h>
using namespace std;


int n;
string s;
int m;
bool dp[10005];
int q[1000005];
int nxt[1000005][27];
string ss[100005];
int pred[10005];

int all;
void add(int x,int y,string z,int num){
    if (y==z.size()) {
        q[x]=num;
        return;
    }
    int xx=z[y]-'a';
    if (nxt[x][xx]==0) nxt[x][xx]=++all;
    add(nxt[x][xx],y+1,z,num);
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    cin>>s;
    dp[0]=true;
    cin>>m;
    for (int i=1;i<=m;++i) {
        cin>>ss[i];
        string sk=ss[i];
      //  reverse(sk.begin(),sk.end());
        for (int i=0;i<sk.size();++i)
            if (sk[i]>='A' && sk[i]<='Z') sk[i]=char(sk[i]-'A'+'a');
        add(0,0,sk,i);
    }
    for (int i=1;i<=n;++i) {
        int v=0;
        int now=i-1;
        while (now!=-1) {
            int x=s[now]-'a';
            if (nxt[v][x]==0) break;
            v=nxt[v][x];
            if (dp[now] && q[v]) {
                dp[i]=true;
                pred[i]=q[v];
                break;
            }
            --now;
        }
    }
    vector<int> qq;

    while (n) {
        qq.push_back(pred[n]);
        n-=ss[pred[n]].size();
    }
    for (int i=qq.size()-1;i>=0;--i)
        cout<<ss[qq[i]]<<" ";
}