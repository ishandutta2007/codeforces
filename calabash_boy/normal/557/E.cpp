//
// Created by Administrator on 2018/12/10.
//

#include<bits/stdc++.h>
using namespace std;
const int maxn = 5000*5000+100;
char s[5005];
bool ok[5005][5005];
int n;
struct Trie{
    int nxt[maxn][2];
    int sum[maxn];
    int Sum[maxn];
    int root,cnt;
    int last_pos,last_r;
    Trie():root(0),cnt(0){}
    int newnode(){
        cnt ++;
        memset(nxt[cnt],0,sizeof nxt[cnt]);
        sum[cnt] = Sum[cnt] = 0;
        return cnt;
    }
    void insert(int l,int r){

        int now = last_pos;
        for (int i=last_r+1;i<=r;i++){
            int ch = s[i] - 'a';
            if (!nxt[now][ch])nxt[now][ch] = newnode();
            now = nxt[now][ch];
        }
        sum[now] ++;
        Sum[now] ++;
        last_r = r;
        last_pos = now;
    }
    string query(int k){
        string ans = "";
        int now = root;
        while (1){
            if (k<=Sum[now])break;
            k -= Sum[now];
            if (nxt[now][1] && nxt[now][0]){
                if (k > sum[nxt[now][0]]){
                    k -= sum[nxt[now][0]];
                    ans += 'b';
                    now = nxt[now][1];
                }else{
                    ans += 'a';
                    now = nxt[now][0];
                }
            }else if (nxt[now][0]){
                ans += 'a';
                now = nxt[now][0];
            }else if (nxt[now][1]){
                ans += 'b';
                now = nxt[now][1];
            }else assert(0);
        }
        return ans;
    }
    void build(){
        for (int i=cnt;i>=1;i--){
            sum[i] += sum[nxt[i][0]] + sum[nxt[i][1]];
        }
    }
    void debug(){
        for (int i=0;i<=cnt;i++){
            printf("nxt[%d][0] = %d nxt[%d][1] = %d sum[%d] = %d\n",i,nxt[i][0],i,nxt[i][1],i,sum[i]);
        }
    }
}trie;
int main(){
    scanf("%s",s);
    int n = strlen(s);
    int k;
    scanf("%d",&k);
    for (int i=0;i<n;i++){
        ok[i][i] = 1;
        if (i+1 <n){
            ok[i][i+1] = s[i] == s[i+1];
        }
        if (i+2 <n){
            ok[i][i+2] = s[i] == s[i+2];
        }
        if (i+3 <n){
            ok[i][i+3] = s[i] == s[i+3];
        }
    }
    for (int i=5;i<=n;i++){
        for (int l = 0;l+i-1<n;l++){
            ok[l][l+i-1] = ok[l+2][l+i-3] && s[l] == s[l+i-1];
           // cerr<<l<<" "<<l+i-1<< " "<<ok[l+2][l+i-3]<<endl;
        }
    }
    for (int i=0;i<n;i++){
        trie.last_pos = 0;
        trie.last_r=i-1;
        for (int j=i;j<n;j++){
            if (ok[i][j]){
              //  cerr<<i<<" "<<j<<endl;
                trie.insert(i,j);
            }
        }
    }
    trie.build();
    //trie.debug();
    cout<<trie.query(k)<<endl;
    return 0;
}