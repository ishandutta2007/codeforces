#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 100;
int a[maxn];
int ans[maxn];
bool ok1[maxn];
bool ok2[maxn];
int id[maxn];
int n;
char s[maxn];
void output(int x){
    for (int i=1;i<=x;i++){
        ans[id[i]] = 1;
    }
    for (int i=x+1;i<=n;i++){
        ans[id[i]] = 2;
    }
    for (int i=1;i<=n;i++){
        printf("%d",ans[i]);
    }
    puts("");
}
vector<int> idx[11];
vector<int> idx1,idx2;
bool check(int share){
    int ed = share - 1;
    idx1.clear();
    idx2.clear();
    for (int i=1;i<=n;i++){
        ans[i] = 0;
    }
    for (int i=0;i<=ed;i++){
        for (int v : idx[i]){
            ans[v] = 1;
            idx1.push_back(v);
        }
    }
    for (int i=share + 1;i <= 9;i ++){
        for (int v : idx[i]){
            ans[v] = 2;
            idx2.push_back(v);
        }
    }
    sort(idx1.begin(),idx1.end());
    sort(idx2.begin(),idx2.end());
    int max1 = -1;
    int min2 = n + 1;
    for (int i=1;i<idx1.size();i++){
        max1 = max(max1,idx1[i]);
        if (a[idx1[i]] < a[idx1[i-1]])return false;
    }
    for (int i=1;i<idx2.size();i++){
        min2 = min(min2,idx2[i]);
        if (a[idx2[i]] < a[idx2[i-1]])return false;
    }
    if (idx1.size())max1 = max(max1,idx1.front());
    if (idx2.size())min2 = min(min2,idx2.front());
    for (int i=1;i<=max1;i++){
        if (ans[i] == 0){
            ans[i] = 2;
        }
    }
    for (int i=min2;i<=n;i++){
       if (a[i] == share && ans[i] != 0)return false;
       if (a[i] == share)ans[i] = 1;
    }
    for (int i=1;i<=n;i++){
        ans[i] = max(ans[i],1);
    }
    idx1.clear();
    idx2.clear();
    for (int i=1;i<=n;i++){
        if(ans[i] == 1)idx1.push_back(i);
        else idx2.push_back(i);
    }
    for (int i=1;i<idx1.size();i++){
        max1 = max(max1,idx1[i]);
        if (a[idx1[i]] < a[idx1[i-1]])return false;
    }
    for (int i=1;i<idx2.size();i++){
        min2 = min(min2,idx2[i]);
        if (a[idx2[i]] < a[idx2[i-1]])return false;
    }
    for (int i=1;i<=n;i++){
        printf("%d",ans[i]);
    }
    puts("");
    return true;
}
void solve(){
    scanf("%d",&n);
    scanf("%s",s+1);
    for (int i=0;i<=9;i++)idx[i].clear();
    for (int i=1;i<=n;i++){
        a[i] = s[i] - '0';
        idx[a[i]].push_back(i);
        id[i] = i;
    }
    bool succ = true;
    for (int i=1;i<=n;i++){
        if (a[i] <a[i-1])succ = false;
    }
    if (succ){
        for (int i=1;i<=n;i++){
            printf("1");
        }
        puts("");
        return;
    }
    for (int ed = 0;ed <= 9;ed ++){
        if (check(ed)){
           // cerr<<ed<<endl;
            return;
        }
    }
    puts("-");
}
int main(){
    int T;
    scanf("%d",&T);
    while (T--){
        solve();
    }
 
    return 0;
}