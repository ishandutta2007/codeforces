// Created by calabash_boy on 19-11-20.
#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e6+100;
const int mod = 51123987;
struct Palindromic_AutoMaton{
    int s[maxn],now;
    vector<int> fail,l,dep;
    int last,tot;
    vector<int> diff,anc,g;int f[maxn],F[maxn];
    vector<int> FIRST,DES,NXT,CH;int TOT;
    void add_edge(int x,int y,int w){
        TOT++;
        DES.push_back(y);
        CH.push_back(w);
        NXT.push_back(FIRST[x]);
        FIRST[x] = TOT;
    }
    int get_edge(int x,int ch){
        for (int t = FIRST[x];t;t=NXT[t]){
            if (CH[t] == ch)return DES[t];
        }
        return 0;
    }
    void clear(){
        //1root 0root
        fail.resize(2,0);
        l.resize(2,0);
        dep.resize(2,0);
        diff.resize(2,0);
        anc.resize(2,0);
        g.resize(2,0);
        DES.resize(1,0);
        NXT.resize(1,0);
        CH.resize(1,0);
        FIRST.resize(2,0);
        s[0] = l[1] = -1;
        fail[0] = tot = now =1;
        last = l[0] = 0;
    }
    Palindromic_AutoMaton(){clear();}
    int newnode(int len){
        tot++;
        fail.push_back(0);
        l.push_back(len);
        dep.push_back(0);
        diff.push_back(0);anc.push_back(0);
        FIRST.push_back(0);
        g.push_back(0);
//        fail[tot]=0;l[tot]=len;
        return tot;
    }
    int get_fail(int x){
        while (s[now-l[x]-2]!=s[now-1])x = fail[x];
        return x;
    }
    void add(int ch){
        s[now++] = ch;
        int cur = get_fail(last);
        if(get_edge(cur,ch) == 0){
            int tt = newnode(l[cur]+2);
            fail[tt] = get_edge(get_fail(fail[cur]),ch);
            dep[tt] = dep[fail[tt]] + 1;
            add_edge(cur,tt,ch);
//            nxt[cur][ch] = tt;
            diff[tt] = l[tt] - l[fail[tt]];
            anc[tt] = diff[tt] == diff[fail[tt]]? anc[fail[tt]] : fail[tt];
        }
        last = get_edge(cur,ch);
//        last = nxt[cur][ch];
    }
    void trans(int i){
        F[i] = (F[i-1] + dep[last]) % mod;
        for (int p = last;p>1;p = anc[p]){
            g[p] = F[i - l[anc[p]] - diff[p]];
            if (diff[p] == diff[fail[p]]){
                (g[p] += g[fail[p]]) %= mod;
            }
            (f[i] += g[p]) %= mod;
        }

    }
    int init(char* s){
        int ans = 0;
        int n = strlen(s + 1);
        for (int i=1;i<=n;i++){
            add(s[i] - 'a');
            trans(i);
            (ans += f[i]) %= mod;
        }
        int tot = F[n];
        ans = (1ll * tot * (tot -1) / 2 % mod - ans + mod) % mod;
        return ans;
    }
}pam;
char s[maxn];
int main(){
    int n;
    cin>>n;
    scanf("%s",s + 1);
    cout<<pam.init(s)<<endl;
    return 0;
}