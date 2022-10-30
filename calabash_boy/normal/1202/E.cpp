// Created by calabash_boy on 18-6-5.
// HDU 6138
//
// query:strx stry p,pstrxstryp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5+100;
ll cntL[maxn];
ll cntR[maxn];
struct Aho_Corasick_Automaton{
    //basic
    int nxt[maxn][26],fail[maxn];
    ll cnt[maxn];
    int root,tot;
    void clear(){
        memset(nxt[0],0,sizeof nxt[0]);
        root = tot=0;
    }
    int newnode(){
        tot++;
        memset(nxt[tot],0,sizeof nxt[tot]);
        cnt[tot] = 0;
        fail[tot] = 0;
        return tot;
    }
    void insert(string str){
        int now = root;
        for (int i=0;i<str.size();i++){
            int id = str[i]-'a';
            if(!nxt[now][id])nxt[now][id] = newnode();
            now = nxt[now][id];
        }
        cnt[now] ++;
    }
    void build(){
        fail[root] = root;
        queue<int>Q;Q.push(root);
        while (!Q.empty()){
            int head = Q.front();Q.pop();
            for (int i=0;i<26;i++){
                if(!nxt[head][i])continue;
                int temp = nxt[head][i];
                fail[temp] = fail[head];
                while (fail[temp]&&!nxt[fail[temp]][i]){
                    fail[temp] = fail[fail[temp]];
                }
                if(head&&nxt[fail[temp]][i])fail[temp] = nxt[fail[temp]][i];
                cnt[temp] += cnt[fail[temp]];
                Q.push(temp);
            }
        }
    }
    void run(string s,ll *ANS){
        int now = root;
        for (int i = 0;i < s.size();i++){
            int ch = s[i] - 'a';
            while (now != root and !nxt[now][ch])now = fail[now];
            now = nxt[now][ch];
            ANS[i] = cnt[now];
        }
    }
}acam;
string s;
vector<string> vec(0);
void work(ll * cnt){
    acam.clear();
    for (auto t : vec){
        acam.insert(t);
    }
    acam.build();
    acam.run(s,cnt);
}
int main(){
    cin>>s;
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        string temp;
        cin>>temp;
        vec.push_back(temp);
    }
    work(cntL);
    reverse(s.begin(),s.end());
    for (auto &t : vec){
        reverse(t.begin(),t.end());
    }
    work(cntR);
//    for (int i=0;i<s.size();i++){
//        cerr<<"cntL["<<i<<"]="<<cntL[i]<<endl;
//    }
//
//    for (int i=0;i<s.size();i++){
//        cerr<<"cntR["<<i<<"]="<<cntL[s.size() - 1 - i]<<endl;
//    }
    ll ans = 0;
    for (int i=0;i<s.size()-1;i++){
        ans += cntL[i] * cntR[s.size() - i - 2];
    }
    cout<<ans<<endl;
    return 0;
}