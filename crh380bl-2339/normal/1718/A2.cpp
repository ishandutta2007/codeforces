#include<bits/stdc++.h>
using namespace std;
map<int,int>M;
set<int>S;
int a[100005],f[100005];
int last[100005];
void work(){
    M.clear();
    S.clear();
    int n,i;
    M[0]=0;S.insert(0);
    scanf("%d",&n);
    for(i=1;i<=n;++i){
        scanf("%d",&a[i]);
        a[i]^=a[i-1];
        //printf("%d\n",M.find(a[i]));
        if(S.find(a[i])==S.end()){
            last[i]=-1;
            M[a[i]]=i;
        }
        else{
            //printf("%d:%d %d\n",i,a[i],M[a[i]]);
            last[i]=M[a[i]];
            M[a[i]]=i;
        }
        S.insert(a[i]);
    }
    //for(i=1;i<=n;++i)printf("%d ",last[i]);puts("");
    for(i=1;i<=n;++i)f[i]=1000000000;
    for(i=1;i<=n;++i){
        f[i]=min(f[i],1+f[i-1]);
        if(last[i]!=-1)f[i]=min(f[i],f[last[i]] + i - last[i] - 1);
    }
    printf("%d\n",f[n]);
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        work();
    }
    return 0;
}