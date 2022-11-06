#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005];
vector<int>A,B;
void work(){
    int n,i,j;
    long long ans=0;
    scanf("%d",&n);
    for(i=1;i<=n;++i){
        scanf("%d",&a[i]);
    }
    A.clear();
    B.clear();
    for(i=1;i<=n;++i){
        scanf("%d",&b[i]);
        ans+=2LL*b[i];
    }
    for(i=1;i<=n;++i){
        if(a[i]==1){
            A.push_back(b[i]);
        }
        else B.push_back(b[i]);
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    if(A.size()==B.size()){
        ans-=min(*A.begin(),*B.begin());
    }
    else if(A.size()>B.size()){
        int m = A.size()-B.size();
        for(i=0;i<m;++i)ans-=A[i];
    }
    else{
        int m=B.size()-A.size();
        for(i=0;i<m;++i)ans-=B[i];
    }
    printf("%lld\n",ans);
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        work();
    }
    return 0;
}