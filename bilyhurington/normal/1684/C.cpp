#include<bits/stdc++.h>
using namespace std;
int T,n,m,a[200010],b[200010];
#define id(x,y) (m*(x-1)+y)
void solve(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&a[id(i,j)]);
            b[id(i,j)]=a[id(i,j)];
        }
    }
    vector<int> vec;
    for(int i=1;i<=n;i++){
        sort(b+id(i,1),b+id(i,m)+1);
        // for(int j=1;j<=m;j++) printf("%d ",a[id(i,j)]);
        // for(int j=1;j<=m;j++) printf("%d ",b[id(i,j)]);
        for(int j=1;j<=m;j++){
            if(a[id(i,j)]!=b[id(i,j)]){
                vec.push_back(j);
            }
        }
    }
    sort(vec.begin(),vec.end());
    vec.erase(unique(vec.begin(),vec.end()),vec.end());
    if(vec.size()>2) puts("-1");
    else if(vec.size()==2){
        for(int i=1;i<=n;i++) swap(a[id(i,vec[0])],a[id(i,vec[1])]);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(a[id(i,j)]!=b[id(i,j)]){
                    puts("-1");
                    return;
                }
            }
        }
        printf("%d %d\n",vec[0],vec[1]);
    }
    else puts("1 1");
}
int main(){
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}