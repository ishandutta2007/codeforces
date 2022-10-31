#include <bits/stdc++.h>
#define MAX_N 210
#define SIGMA 10
#define MLEN 1000010
using namespace std;
 
int n, m, q, values[MAX_N*MAX_N];
int x[SIGMA], y[SIGMA], nxt[MAX_N*MAX_N];
 
bool in_cycle[MAX_N*MAX_N];
int vis[MAX_N*MAX_N], num_cyc=0, idx[MAX_N*MAX_N];
bool has[MAX_N*MAX_N][SIGMA], vis2[MAX_N*MAX_N];
int first_val[SIGMA];
 
vector<int> rev[MAX_N*MAX_N], cycles[MAX_N*MAX_N];
 
void dfs_cycles(int a) {
    if (vis[a]==2) return ;
    if (vis[a]==1) {
        in_cycle[a]=true;
        vis[a]=2;
        return ;
    }
    vis[a]=1;
    dfs_cycles(nxt[a]);
    vis[a]=2;
}
 
void getcycles() {
    memset(vis,0,sizeof(vis));
    memset(vis2,0,sizeof(vis2));
    memset(in_cycle,0,sizeof(in_cycle));
    memset(has,0,sizeof(has));
    for (int i=0; i<n; i++) {
        dfs_cycles(i);
        if (in_cycle[i] && !vis2[i]) {
            int j=i;
            do {
                in_cycle[j]=true;
                vis2[j]=true;
                idx[j]=num_cyc;
                has[num_cyc][values[j]]=true;
                cycles[num_cyc].push_back(j);
                j=nxt[j];
            } while (j!=i);
            num_cyc++;
        }
    }
}
 
void reverse_graph() {
    for (int i=0; i<n; i++) {
        if (!in_cycle[i]) {
            rev[nxt[i]].push_back(i);
        }
    }
}
 
bool dfs_query(int a, int pos, string& s) {
    if (pos<s.length() && values[a]==s[pos]-'0') pos++;
    if (pos==s.length()) return true;
    vis2[a]=true;
    for (auto val: rev[a]) {
        if (dfs_query(val,pos,s)) return true;
    }
    return false;
}
 
void query(string& s) {
    memset(vis2,0,sizeof(vis2));
    for (int i=0; i<n; i++) {
        if (in_cycle[i] && !vis2[i]) {
            int pos=-1;
            for (int j=0; j<SIGMA; j++) {
                if (first_val[j]!=-1 && !has[idx[i]][j]) {
                    if (pos==-1) pos=first_val[j];
                    else pos=min(pos,first_val[j]);
                }
            }
            if (pos==-1) {
                cout << "YES\n";
                return ;
            }
            for (int j: cycles[idx[i]]) {
                if (dfs_query(j,pos,s)) {
                    cout << "YES\n";
                    return ;
                }
            }
        }
    }
    cout << "NO\n";
}
 
int main(void) {
    char ex[MAX_N][MAX_N];
    cin >> n >> m >> q;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> ex[i][j];
            values[m*i+j]=ex[i][j]-'0';
        }
    }
    for (int i=0; i<SIGMA; i++) {
        cin >> x[i] >> y[i];
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            int ni=i+x[values[m*i+j]], nj=j+y[values[m*i+j]];
            if (ni<0 || nj<0 || ni>=n || nj>=m) {
                ni=i;
                nj=j;
            }
            nxt[m*i+j]=ni*m+nj;
        }
    }
    n*=m;
    getcycles();
    reverse_graph();
    for (int i=0; i<q; i++) {
        memset(first_val,-1,sizeof(first_val));
        string s="", t;
        cin >> t;
        for (int j=0; j<t.length(); j++) {
            s+=t[t.length()-1-j];
            first_val[t[j]-'0']=t.length()-1-j;
        }
        query(s);
    }
    return 0;
}