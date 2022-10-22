#include<bits/stdc++.h>
#define outY puts("YES")
#define outN puts("NO")
using namespace std;
const int maxn=1010;
int i,j,k,n,m,T;
int a[maxn],d[maxn],C[maxn];
int Query(int x){
    cout<<"? "<<x<<endl;
    int z;cin>>z;
    return z;
}
vector<int>tmp;
int main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(i=1;i<=n;i++)scanf("%d",&d[i]),C[i]=0;
        int Max=0,K=0;
        d[0]=-1;
        while(1){
            Max=0;
            for(i=1;i<=n;i++)
                if(!C[i])if(d[Max]<d[i])Max=i;
            if(!Max)break;
            // cerr<<"Max="<<Max<<' '<<C[Max]<<endl;
            tmp.clear();
            for(i=1;i<=d[Max];i++){
                int u=Query(Max);
                if(C[u]){
                    C[Max]=C[u];
                    for(int x:tmp)C[x]=C[u];
                    break;
                }else tmp.push_back(u);
            }
            // cerr<<"OK"<<endl;
            // cerr<<"Max="<<Max<<' '<<C[Max]<<endl;
            if(!C[Max]){
                C[Max]=++K;
                cerr<<Max<<' '<<K<<endl;
                for(int x:tmp)C[x]=K;
            }
        }
        cout<<"!";
        for(i=1;i<=n;i++)cout<<' '<<C[i];cout<<endl;
    }
}
/*



*/