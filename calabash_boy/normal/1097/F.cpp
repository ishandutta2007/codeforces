#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+100;
#define lowbit(x) x&-x
#define inf 1000000000
bitset<7005>F[N],A[N],ans;
vector<int>G[N];
int n,m;
int main() {
    scanf("%d%d",&n,&m);
    for (int i=7000;i;i--) {
        F[i][i]=1;
        for (int j=2*i;j<=7000;j+=i)
            F[i]^=F[j];
    }
    for (int i=1;i<=7000;i++)
        for (int j=i;j<=7000;j+=i) G[j].push_back(i);
    for (int i=1;i<=m;i++) {
        int id,x,y,z;
        scanf("%d%d%d",&id,&x,&y);
        if (id==1) {
            A[x]=A[0];
            for (int j=0;j<G[y].size();j++) A[x][G[y][j]]=1;
        }
        else if (id==2) {
            scanf("%d",&z);
            A[x]=A[z]^A[y];
        }
        else if (id==3) {
            scanf("%d",&z);
            A[x]=A[z]&A[y];
        }
        else {
            ans=A[x]&F[y];
            printf("%d",int(ans.count())&1);
        }
    }
}