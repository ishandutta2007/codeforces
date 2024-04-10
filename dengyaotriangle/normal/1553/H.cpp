#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=19;
const int maxl=1<<maxn;
int n,k;
bool x[maxl];
vector<int> vi[maxl][2];
int cur[maxl],ans[maxl];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        int a;cin>>a;
        x[a]=1;
        vi[a][0].push_back(0);vi[a][1].push_back(0);//0: min 1:max
    }
    memset(ans,0x3f,sizeof(ans));
    for(int t=k-1;t>=0;t--){
        memset(cur,0x3f,sizeof(cur));
        int s=k-t,sh=k-t-1;
        for(int i=0;i<(1<<t);i++){
            int l=i<<1,r=l+1;
            vector<int> v[2][2]={{vi[l][0],vi[l][1]},{vi[r][0],vi[r][1]}};
            vector<int> z[2];
            if(!x[l]&&!x[r]){
                x[i]=0;
            }else if(!x[r]){
                z[0]=v[0][0];z[1]=v[0][1];
                for(int p=0;p<2;p++){
                    z[p].resize(1<<s);
                    int lsh=1<<sh;
                    for(int i=lsh;i<(1<<s);i++)z[p][i]=z[p][i-lsh]+lsh;
                }
                x[i]=1;
            }else if(!x[l]){
                z[0]=v[1][0];z[1]=v[1][1];
                for(int p=0;p<2;p++){
                    z[p].resize(1<<s);
                    int lsh=1<<sh;
                    for(int i=lsh;i<(1<<s);i++)z[p][i]=z[p][i-lsh];
                    for(int i=0;i<lsh;i++)z[p][i]+=lsh;
                }
                x[i]=1;
            }else{
                z[0]=v[0][0];z[1]=v[1][1];
                z[0].resize(1<<s);z[1].resize(1<<s);
                int lsh=1<<sh;
                for(int i=lsh;i<(1<<s);i++)z[0][i]=v[1][0][i-lsh];
                for(int i=0;i<lsh;i++)z[1][i]+=lsh;
                for(int i=lsh;i<(1<<s);i++)z[1][i]=v[0][1][i-lsh]+lsh;
                for(int i=0;i<lsh;i++){
                    int k=v[1][0][i]+lsh-v[0][1][i];
                    cur[i]=min(cur[i],k);
                }
                for(int i=lsh;i<(1<<s);i++){
                    int k=v[0][0][i-lsh]+lsh-v[1][1][i-lsh];
                    cur[i]=min(cur[i],k);
                }
                x[i]=1;
            }
            vi[i][0]=z[0];vi[i][1]=z[1];
        }
        for(int i=0;i<(1<<s);i++){
            for(int j=0;j<(1<<t);j++){
                int k=i|(j<<s);
                ans[k]=min(ans[k],cur[i]);
            }
        }
    }
    for(int i=0;i<(1<<k);i++)cout<<ans[i]<<' ';
    return 0;
}