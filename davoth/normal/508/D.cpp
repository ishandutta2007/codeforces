#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
const int MAXN = 2e5 + 5;
int n;
string a[MAXN];
vector<pair<pair<int,int>,int> > adj[62][62];
char m[62];
int ind[62][62];
bool bc[62][62];
string ans;
int last[62][62];
int pointer[62][62];
int gt(char c){
    if(c>='a' && c<='z') return c-'a';
    if(c>='A' && c<='Z') return c-'A'+26;
    else return c-'0'+52;
}
void dfs(int v,int u) {
    bc[v][u] = true;
    while(pointer[v][u]<adj[v][u].size()){
        pair<pair<int,int>,int> p=adj[v][u][pointer[v][u]++];
        int x=p.F.F,y=p.F.S;
        dfs(x,y);
    }
    ans+=m[u];
}

int main() {
    fast_io;
    cin >> n;
    for(int i=0; i<26; i++) m[i]='a'+i;
    for(int i=26; i<52; i++) m[i]='A'+i-26;
    for(int i=52; i<62; i++) m[i]='0'+i-52;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        int x=gt(a[i][0]),y=gt(a[i][1]),z=gt(a[i][2]);
        adj[x][y].push_back({{y,z},i});
        ind[y][z]++;
    }
    int odd = 0, odi = -1, li = -1,odj=-1,lj=-1;
    for(int i=0; i<62; i++){
        for(int j=0; j<62; j++){
            if(adj[i][j].size()!=ind[i][j]){
                if(abs((int)adj[i][j].size()-ind[i][j])>1) return cout << "NO",0;
                odd++;
                if(adj[i][j].size()<ind[i][j]) continue;
                odi=i;
                odj=j;
            }
            else if(!adj[i][j].empty()) li=i,lj=j;
        }
    }
    int sx,sy;
    if (odd != 2 && odd != 0) return cout << "NO", 0;
    if (odd == 0) sx = li,sy=lj;
    else sx = odi,sy=odj;
    int sz[62][62];
    for(int i=0; i<62; i++) for(int j=0; j<62; j++) sz[i][j]=adj[i][j].size();
    dfs(sx,sy);
    for (int i = 0; i < 62; i++) for(int j=0; j<62; j++) if (!bc[i][j] && sz[i][j]) return cout << "NO ", 0;
    ans+=m[sx];
    string ans2;
    for(int i=ans.size()-1; i>=0; i--) ans2+=ans[i];
    cout << "YES\n" << ans2;
    return 0;
}