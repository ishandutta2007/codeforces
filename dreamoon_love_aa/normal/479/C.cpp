#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
vector<pair<int,int> >pp;
int dp[5010];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        pp.push_back(make_pair(x,y));
    }
    sort(pp.begin(),pp.end());
    dp[0]=pp[0].second;
    for(int i=1;i<n;i++){
        if(pp[i].second>=dp[i-1])dp[i]=pp[i].second;
        else dp[i]=pp[i].first;
    }
    printf("%d\n",dp[n-1]);
    return 0;
}