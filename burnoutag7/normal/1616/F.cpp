#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vec;
typedef vector<vec> mat;

vec gauss(mat &a){
    int n=a.size(),m=a[0].size()-1;
    int p=0;
    for(int i=0;i<m&&p<n;i++){
        for(int j=p;j<n;j++)if(a[j][i]){
            swap(a[p],a[j]);
            break;
        }
        if(!a[p][i])continue;
        for(int j=m;j>=i;j--)a[p][j]=a[p][j]*a[p][i]%3;
        for(int j=p+1;j<n;j++)for(int k=m;k>=i;k--)a[j][k]=(a[j][k]-a[j][i]*a[p][k]+9)%3;
        p++;
    }
    for(int i=p;i<n;i++)if(a[i][m])return vec();
    vec r(m,0);
    for(p--;p>=0;p--){
        int i=0;while(!a[p][i])i++;
        for(int j=m-1;j>i;j--)a[p][m]=(a[p][m]-r[j]*a[p][j]+9)%3;
        if(a[p][m]&&!a[p][i])return vec();
        r[i]=a[p][m];
    }
    return r;
}

int n,m,U[300],V[300],W[300],id[300],vac,g[70][70];

void addedge(vec &v,int e){
    if(id[e]==-1)v[vac]=(v[vac]+3-W[e])%3;
    else v[id[e]]=1;
}

void mian(){
    cin>>n>>m;
    memset(g,-1,sizeof(g));
    vac=0;
    for(int i=0;i<m;i++){
        int &u=U[i],&v=V[i],&w=W[i];
        cin>>u>>v>>w;
        u--;v--;
        g[u][v]=g[v][u]=i;
        if(w==-1)id[i]=vac++;
        else id[i]=-1;
    }
    mat a;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++)if(g[i][j]!=-1){
            for(int k=j+1;k<n;k++)if(g[i][k]!=-1&&g[j][k]!=-1){
                vec v(vac+1,0);
                addedge(v,g[i][j]);
                addedge(v,g[i][k]);
                addedge(v,g[j][k]);
                a.emplace_back(v);
            }
        }
    }
    vec r=a.empty()?vec(vac,0):gauss(a);
    if(r.empty()){
        cout<<"-1\n";
        return;
    }
    for(int i=0;i<m;i++)if(id[i]==-1)cout<<W[i]<<' ';
    else cout<<(r[id[i]]?r[id[i]]:3)<<' ';
    cout<<'\n';
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--)mian();

    return 0;
}