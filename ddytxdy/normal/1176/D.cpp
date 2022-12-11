#include<bits/stdc++.h>
using namespace std;
const int N=3e6+50;
int n,a[N],p[N],tot,id[N],mindiv[N],cnt[N];
vector<int>ans;
int main(){
    for(int i=2;i<N;i++){
        if(!mindiv[i])mindiv[i]=p[++tot]=i;
        for(int j=1,y;j<=tot&&(y=p[j]*i)<N&&p[j]<=mindiv[i];j++)
            mindiv[y]=p[j];
    }
    for(int i=1;i<=tot;i++)id[p[i]]=i;
    scanf("%d",&n);n*=2;
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    for(int i=n;i;i--){
        if(cnt[a[i]]){cnt[a[i]]--;continue;}
        // cout<<1<<" ";
        if(id[a[i]])cnt[id[a[i]]]++,ans.push_back(id[a[i]]);
        else ans.push_back(a[i]),cnt[a[i]/mindiv[a[i]]]++;
    }
    for(int i=0;i<ans.size();i++)printf("%d ",ans[i]);
    return 0;
}