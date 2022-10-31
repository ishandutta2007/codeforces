#include <bits/stdc++.h>
using namespace std;


bool used[505][505];
long long  n,m,k,kol;
string s[505];
pair<long long,long long>  q[505*505];
void bfs(long long x,long long y){
    long long l=1; long long r=1;
    used[x][y]=true;
    q[1]=make_pair(x,y);

    while (l<=r){
        x=q[l].first;
        y=q[l].second;
        if (s[x-1][y]=='.' && used[x-1][y]==false && r<k && x-1>0){
            used[x-1][y]=true;
            ++r;
            q[r]=make_pair(x-1,y);
        }
        if (s[x+1][y]=='.' && used[x+1][y]==false && r<k && x+1<=n){
            used[x+1][y]=true;
            ++r;
            q[r]=make_pair(x+1,y);
        }
        if (s[x][y-1]=='.' && used[x][y-1]==false && r<k && y-1>=0){
            used[x][y-1]=true;
            ++r;
            q[r]=make_pair(x,y-1);
        }
        if (s[x][y+1]=='.' && used[x][y+1]==false && r<k && y+1<m){
            used[x][y+1]=true;
            ++r;
            q[r]=make_pair(x,y+1);
        }
        ++l;
        if (r==k) break;
    }
}
int main(){
  //  freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
    cin>>n>>m>>k;
    for (int i=1;i<=n;++i){
        cin>>s[i];
        for (int j=0;j<s[i].size();++j)
            if (s[i][j]=='.') ++kol;
    }
    k=kol-k;
    for (int i=1;i<=n;++i)
        for (int j=0;j<m;++j)
    if (s[i][j]=='.'){
        bfs(i,j);
        for (int ii=1;ii<=n;++ii){
            for (int jj=0;jj<m;++jj){
                if (s[ii][jj]=='.' && used[ii][jj]==false) cout<<"X";
                else cout<<s[ii][jj];
            }
            cout<<'\n';
        }
        return 0;
    }
}