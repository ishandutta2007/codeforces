#include <bits/stdc++.h>
using namespace std;

int n,m;
string ss;
char a[100][100];
char b[100][100];
int ans;
vector<pair<int,int> > v;
void recurs(int x,int y,char c){
    if (a[x][y]==c) return ;
    char q=a[x][y];
    if (q=='L' && c=='U') {
        recurs(x+1,y,'L');
        a[x][y]='U';
        a[x][y+1]='U';
        a[x+1][y]='D'; a[x+1][y+1]='D';
        ++ans;
        v.push_back(make_pair(x,y));
        return;
    }
    if (q=='U' && c=='L'){
        recurs(x,y+1,'U');
        a[x][y]='L'; a[x][y+1]='R';
        a[x+1][y]='L'; a[x+1][y+1]='R';
        ++ans;
        v.push_back(make_pair(x,y));
        return;
    }
    if (q=='R' && c=='L') {
        recurs(x+1,y-1,'L');
        recurs(x,y+1,'U');
        a[x][y-1]='U';
        a[x+1][y-1]='D';
        a[x][y]='L'; a[x][y+1]='R';
        a[x+1][y]='L'; a[x+1][y+1]='R';
        ans+=2;
        v.push_back(make_pair(x,y-1));
        v.push_back(make_pair(x,y));
        return;
    }
    if (q=='D' && c=='U'){
        recurs(x-1,y+1,'U');
        recurs(x+1,y,'L');
        a[x-1][y]='L'; a[x-1][y+1]='R';
        a[x][y]='U'; a[x][y+1]='U';
        a[x+1][y]='D'; a[x+1][y+1]='D';
        ans+=2;
        v.push_back(make_pair(x-1,y));
        v.push_back(make_pair(x,y));
    }
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;++i){
        cin>>ss;
        for (int j=1;j<=m;++j)
            a[i][j]=ss[j-1];
    }
    for (int i=1;i<=n;++i){
        cin>>ss;
        for (int j=1;j<=m;++j)
            b[i][j]=ss[j-1];
    }
    for (int i=1;i<=n;++i)
        for (int j=1;j<=m;++j)
            recurs(i,j,b[i][j]);
    cout<<ans<<'\n';
    for (int i=0;i<v.size();++i){
        cout<<v[i].first<<" "<<v[i].second<<'\n';
    }

}