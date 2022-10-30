#include <bits/stdc++.h>
using namespace std;
long long kl,x,y,n,m,sz1,sz2,sz3;
long long a[100][100];
long long b[100][100];
long long c[100][100];
bool used[1001];
vector<int> v;
void dfs(int i){
    ++kl;
    v.push_back(i);
    used[i]=true;
    for (int j=1;j<=n;++j)
        if (a[i][j]==1 && used[j]==false) dfs(j);
}
int main(){
    cin>>n>>m;
    for (int i=1;i<=m;++i){
        cin>>x>>y;
        a[x][y]=1;
        a[y][x]=1;
    }
    for (int i=1;i<=n;++i) if (used[i]==false){
        kl=0;
        v.clear();
        dfs(i);
        if (kl>3) {
            cout<<"-1";
            return 0;
        }
        if (kl==3){
            ++sz3;
            a[sz3][1]=v[0]; a[sz3][2]=v[1]; a[sz3][3]=v[2];
        } else if (kl==2){
            ++sz2;
            b[sz2][1]=v[0]; b[sz2][2]=v[1];
        } else {
            ++sz1;
            c[sz1][1]=v[0];
        }
    }
    if (sz2>sz1) {
        cout<<"-1";
        return 0;
    }
    if (sz2==sz1){
        for (int i=1;i<=sz3;++i){
            for (int j=1;j<=3;++j)
            cout<<a[i][j]<<" ";
            cout<<'\n';
        }
        for (int i=1;i<=sz2;++i){
            cout<<b[i][1]<<" "<<b[i][2]<<" "<<c[i][1]<<'\n';
        }
        return 0;
    } else {
        if ((sz1-sz2)%3!=0){
            cout<<"-1";
            return 0;
        }
        for (int i=1;i<=sz3;++i){
            for (int j=1;j<=3;++j)
            cout<<a[i][j]<<" ";
            cout<<'\n';
        }
        for (int i=1;i<=sz2;++i){
            cout<<b[i][1]<<" "<<b[i][2]<<" "<<c[i][1]<<'\n';
        }
        for (int i=sz2+1;i<=sz1;i+=3){
            cout<<c[i][1]<<" "<<c[i+1][1]<<" "<<c[i+2][1]<<endl;
        }
    }
}