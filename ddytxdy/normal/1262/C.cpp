#include<bits/stdc++.h>
using namespace std;
const int N=2020;
int T,n,k;char s[N],t[N];
vector<pair<int,int> >ans;
int main(){
    scanf("%d",&T);
    while(T--){
        ans.clear();
        scanf("%d%d%s",&n,&k,s+1);k--;
        for(int i=1;i<=k;i++)t[i*2-1]='(',t[i*2]=')';
        for(int i=1,j=2*k+1;i<=n/2-k;i++,j++)t[j]='(';
        for(int i=1,j=n;i<=n/2-k;i++,j--)t[j]=')';
        for(int i=1,j;i<=n;i++)if(s[i]!=t[i]){
            for(j=i+1;;j++)if(s[j]==t[i])break;
            ans.push_back(make_pair(i,j));
            reverse(s+i,s+j+1);
        }
        printf("%d\n",ans.size());
        for(int i=0;i<ans.size();i++)printf("%d %d\n",ans[i].first,ans[i].second);
    }
    return 0;
}