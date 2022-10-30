// Created by calabash_boy on 19-11-20.
// CF 932G 
// DP
// 3TBD
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+100;
const int INF = INT_MAX / 3;
char s[maxn];
struct Palindromic_AutoMaton{
    int s[maxn],now;
    int nxt[maxn][26],fail[maxn],l[maxn],last,tot;
    int diff[maxn],anc[maxn];
    pair<int,int> g[maxn],f[maxn];
    void clear(){
        //1root 0root
        s[0] = l[1] = -1;
        fail[0] = tot = now =1;
        last = l[0] = 0;
        memset(nxt[0],0,sizeof nxt[0]);
        memset(nxt[1],0,sizeof nxt[1]);
    }
    Palindromic_AutoMaton(){clear();}
    int newnode(int len){
        tot++;
        memset(nxt[tot],0,sizeof nxt[tot]);
        fail[tot]=0;l[tot]=len;
        return tot;
    }
    int get_fail(int x){
        while (s[now-l[x]-2]!=s[now-1])x = fail[x];
        return x;
    }
    void add(int ch){
        s[now++] = ch;
        int cur = get_fail(last);
        if(!nxt[cur][ch]){
            int tt = newnode(l[cur]+2);
            fail[tt] = nxt[get_fail(fail[cur])][ch];
            nxt[cur][ch] = tt;
            diff[tt] = l[tt] - l[fail[tt]];
            anc[tt] = diff[tt] == diff[fail[tt]]? anc[fail[tt]] : fail[tt];
        }
        last = nxt[cur][ch];
    }
    pair<int,int> min_f = {INF,-1};
    void trans(int i){
        f[i] = {INF,-1};
        for (int p = last;p>1;p = anc[p]){
            g[p] = {f[i - l[anc[p]] - diff[p]].first,i - l[anc[p]] - diff[p]};
            if (diff[p] == diff[fail[p]]){
                g[p] = min(g[p],g[fail[p]]);
            }
            // 1
            f[i] = min(f[i],{1 + g[p].first,g[p].second});
        }
        if (i & 1)f[i] = {INF,-1};
        else{
            if (s[i] == s[i-1]){
                if (f[i-2].first < min_f.first){
                    min_f = {f[i-2].first,i-2};
                }
//                min_f = min(min_f,f[i-2].first);
            }else{
                min_f = {INF,-1};
            }
            f[i] = min(f[i],min_f);
        }
    }
    bool check(int l,int r){
        for (int i=l;i<r;i+=2){
            if (s[i] != s[i+1])return false;
        }
        return true;
    }
    void init(char* s){
        cerr<<s+1<<endl;
        f[0] = {0,-1};
        int n = strlen(s + 1);
        for (int i=1;i<=n;i++){
            add(s[i] - 'a');
            trans(i);
        }
        if (f[n].first == INF){
            cout<<-1<<endl;
            return;
        }
        vector<pair<int,int> > ans(0);
        int idx = n;
        while (idx){
            int pre = f[idx].second;
            if(!check(pre+1,idx))
            ans.push_back({pre+1,idx});
            idx = pre;
        }
        cout<<ans.size()<<endl;
        for (auto pr : ans){
            cout<<(pr.first+1)/2<<" "<<pr.second/2<<endl;
        }
    }
}pam;
int main(){
    static char buf[maxn];
    cin>>buf;
    int n = strlen(buf);
    for (int i=0;i < n;i ++){
        s[2 * i+1] = buf[i];
    }
    cin>>buf;
    for (int i=0;i<n;i++){
        s[i*2+2] = buf[i];
    }
    pam.init(s);
    //cout<<pam.init(s)<<endl;
    return 0;
}