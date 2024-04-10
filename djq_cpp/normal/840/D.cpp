#include <cstdio>
#include <vector>
#include <utility>
#include <cstdlib>
using namespace std;
#define rep(k,n) for(int k=0;k<int(n);k++)
typedef pair<int,int> pii;
const int INF=1e9+7;
const int TOT=80;
vector<int> occ[300005];
vector<int> qy[300005];
int pos[300005],a[300005];
int r[300005],x[300005],ans[300005];
int main(){
    srand(19260817);
    int n,q,l;
    scanf("%d%d",&n,&q);
    rep(k,n){
        scanf("%d",&a[k]);
        occ[a[k]].push_back(k);
    }
    rep(k,q){
        scanf("%d%d%d",&l,&r[k],&x[k]);
        l--;r[k]--;
        qy[l].push_back(k);
    }
    rep(i,n){
        rep(j,qy[i].size()){
            int cq=qy[i][j];
            ans[cq]=INF;
            rep(k,TOT){
                int cur=a[(rand()*rand()+rand())%(r[cq]-i+1)+i];
                int cpos=pos[cur]+(r[cq]-i+1)/x[cq];
                if(cpos<occ[cur].size()&&occ[cur][cpos]<=r[cq])ans[cq]=min(ans[cq],cur);
            }
            if(ans[cq]==INF)ans[cq]=-1;
        }
        pos[a[i]]++;
    }
    rep(k,q)printf("%d\n",ans[k]);
    return 0;
}