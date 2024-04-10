#include<bits/stdc++.h>
using namespace std;
const int N=1e5+50;
int T,n;bool va[N],vb[N];
void solve(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)va[i]=vb[i]=0;
    for(int i=1,x;i<=n;i++){
        scanf("%d",&x);int id=0;
        for(int j=1,y;j<=x;j++){
            scanf("%d",&y);if(!id&&!vb[y])id=y;
        }
        if(id)va[i]=vb[id]=1;
    }
    int ia=0,ib=0;
    for(int i=1;i<=n;i++)if(!va[i]){ia=i;break;}
    for(int i=1;i<=n;i++)if(!vb[i]){ib=i;break;}
    if(!ia)puts("OPTIMAL");
    else puts("IMPROVE"),printf("%d %d\n",ia,ib);
}
int main(){
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}