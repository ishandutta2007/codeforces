#include <bits/stdc++.h>
using namespace std;

int n;
int x,y,sum;
int b[1000005];
int a[1000005];
bool t;
vector<int> v[1000005];
int ansx,ansy;
int dfs(int x,int p=-1){
    b[x]=a[x];
    int zz=-1;
    for (int i=0;i<v[x].size();++i){
        int to=v[x][i];
        if (to==p) continue;
        int q=dfs(to,x);
        b[x]+=b[to];
        if (q!=-1 && b[q]==sum/3) {
            if (zz!=-1 && b[zz]==sum/3) {
                t=true;
                ansx=zz;
                ansy=q;
            }
            zz=q;
        }
    }
    if (zz!=-1 && b[x]-b[zz]==sum/3 && b[zz]==sum/3 && x!=v[0][0]){
        t=true;
        ansx=x;
        ansy=zz;
    }
    if (b[x]==sum/3) return x;
    else return zz;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>x>>y;
        v[x].push_back(i);
        a[i]=y;
        sum+=y;
    }
    if (abs(sum)%3>0) {
        cout<<"-1";
        return 0;
    }
    dfs(v[0][0]);
    if (!t) cout<<"-1";
    else cout<<ansx<<" "<<ansy;
}