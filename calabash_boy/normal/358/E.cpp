#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int mp[maxn][maxn];
int n,m;
int sum[maxn];
int gcd(int x,int y){
    if (y == 0)return x;
    return gcd(y, x % y);
}
bool used[maxn][maxn];
pair<int,int> lefttop = make_pair(1005,1005);
vector<int> get_idx(int sam,int d,int n){
    vector<int> X(0);
    X.push_back(sam);
    int t = sam - d;
    while (t>=1){
        X.push_back(t);
        t -= d;
    }
    t = sam + d;
    while (t <= n){
        X.push_back(t);
        t += d;
    }
    sort(X.begin(),X.end());
    return X;
}
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int degree[maxn][maxn];
bool check(int d){
    memset(used,0,sizeof used);
    memset(degree,0,sizeof degree);
    vector<int> X = get_idx(lefttop.first,d,n),
    Y = get_idx(lefttop.second, d,m);
    for (int x : X)for (int y : Y){
        if (mp[x][y] == 1){
            used[x][y] = 1;
            for (int k = 0;k < 4;k ++){
                int xx = x + dx[k] * d;
                int yy = y + dy[k] * d;
                if (xx >= 1 && xx <= n && yy >= 1 && yy <= m && mp[xx][yy]){
                    int cnt = 0;
                    int imin = min(x,xx);
                    int imax = max(x,xx);
                    int jmin = min(y,yy);
                    int jmax = max(y,yy);
                    for (int i=imin;i <= imax;i++)for (int j=jmin;j <= jmax;j++){
                        cnt += mp[i][j];
                        used[i][j] = 1;
                    }
                    if (cnt != 0 && cnt != d+1 && cnt != 2){
                       // cerr<<x<<","<<y<<" and "<<xx<<","<<yy<<" : "<<cnt<<endl;
                        return false;
                    }
                    if (cnt == d + 1){
                        degree[x][y] ++;
                        degree[xx][yy] ++;
                    }
                }
            }
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (mp[i][j] && !used[i][j]){
             //   cerr<<"flow error "<<d<<endl;
                return false;
            }
        }
    }
    int oddcnt = 0;
    for (int x : X)for (int y : Y){
        oddcnt += (degree[x][y]/2) & 1;
    }
    if (oddcnt <= 2)return true;
    else {
     //   cerr<<"degree error "<<d<<endl;
        return false;
    }
    
}
void dfs(int x,int y){
    used[x][y] = 1;
    for (int k = 0;k < 4;k ++){
        int xx = x + dx[k];
        int yy = y + dy[k];
        if (xx >= 1 && xx <= n && yy >= 1 && yy <= m && mp[xx][yy] == 1 && !used[xx][yy]){
            dfs(xx,yy);
        }
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            scanf("%d",&mp[i][j]);
            if (mp[i][j] == 1){
                lefttop = min(lefttop,make_pair(i,j));
            }
        }
    }
    memset(used,0,sizeof used);
    dfs(lefttop.first,lefttop.second);
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (mp[i][j] && !used[i][j]){
                cout<<-1<<endl;
                return 0;
            }
        }
    }
    int len = -1;
    for (int i=1;i<=n;i++){
//        memset(sum,0,sizeof sum);
        int j = 1;
        while (j<=m){
            while (j<=m && mp[i][j] == 0)j++;
            int jj = j;
            while (jj<=m && mp[i][jj] == 1)jj++;
            int Len = jj - j;
            if (Len == 0)break;
            len = max(len,Len);
            j = jj;
        }
    }
    for (int j=1;j<=m;j++){
        int i= 1;
        while (i <= n){
            while (i<=n && mp[i][j] == 0)i ++;
            int ii = i;
            while (ii <=n && mp[ii][j] == 1)ii ++;
            int Len = ii - i;
            if (Len == 0)break;
            len = max(len,Len);
            i = ii;
        }
    }
    len --;
 //  cerr<<len<<endl;
 //   cerr<<lefttop.first<<","<<lefttop.second<<endl;
    int num = 0;
    for (int d = 2;d <=len;d ++){
        if (len % d == 0 && check(d)){
            cout<<d<<" ";
            num ++;
        }
    }
    if (num == 0){
        cout<<-1<<endl;
    }
    return 0;
}