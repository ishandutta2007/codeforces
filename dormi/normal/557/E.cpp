#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXN=5001;
bool halfpali[MAXN][MAXN];
int n;
string s;
string ans;
struct node{
    int cur,tot;
    node* child[2];
    node(){
        cur=0,tot=0;
        child[0]=NULL,child[1]=NULL;
    }
    int insert(int l, int r){
        int am=0;
        if(l<=r&&halfpali[l][r])cur++,am++,tot++;
        if(r+1<n){
            int nxt=s[r+1]-'a';
            if(!child[nxt])child[nxt]=new node();
            int k=child[nxt]->insert(l,r+1);
            tot+=k,am+=k;
        }
        return am;
    }
    void query(int q){
        if(cur>=q)return;
        q-=cur;
        int leftam=(child[0]?child[0]->tot:0);
        if(leftam>=q){
            ans.push_back('a');
            child[0]->query(q);
            return;
        }
        q-=leftam;
        ans.push_back('b');
        child[1]->query(q);
    }
}trie;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>s;
    int q;
    cin>>q;
    n=sz(s);
    for(int i=1;i<=n;i++){
        for(int j=0;j+i<=n;j++){
            if(s[j]==s[j+i-1]) {
                if (j + 2 > j + i - 3 || halfpali[j + 2][j + i - 3]) {
                    halfpali[j][j + i - 1] = true;
                }
            }
        }
    }
    for(int i=0;i<n;i++)trie.insert(i,i-1);
    trie.query(q);
    cout<<ans<<"\n";
    return 0;
}