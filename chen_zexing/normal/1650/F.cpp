#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <climits>
#include <algorithm>
#include <complex>
#include <string.h>
#include <iomanip>
#include <assert.h>
using namespace std;
int dp[100005][205];
int preid[100005][205],pre_v[100005][205];
struct node{
    int id,t,p;
    friend bool operator <(node a,node b){
        return a.p<b.p||a.p==b.p&&a.t<b.t;
    }
};
vector <node> v[100005];
int a[100005];
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n,m,f=1;
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            v[i].clear(),scanf("%d",&a[i]);
        }
        for(int i=1,x,y,z;i<=m;i++){
            scanf("%d%d%d",&x,&y,&z);
            v[x].push_back(node{i,y,z});
        }
        long long now=0;
        vector <int> ans;
        for(int i=1;i<=n;i++){
            dp[0][0]=preid[0][0]=pre_v[0][0]=0;
            for(int j=1;j<=200;j++) dp[0][j]=INT_MAX/2,preid[0][j]=pre_v[0][j]=-1;
            int cnt=0;
            for(auto t:v[i]){
                cnt++;
                for(int j=200;j>=0;j--) {
                    dp[cnt][j] = dp[cnt - 1][j], pre_v[cnt][j] = j, preid[cnt][j] = 0;
                    if (j >= t.p && (long long) dp[cnt - 1][j - t.p] + t.t < dp[cnt][j]) {
                        dp[cnt][j] = dp[cnt - 1][j - t.p] + t.t;
                        preid[cnt][j] = t.id, pre_v[cnt][j] = j - t.p;
                    }
                }
            }
            for(int j=101;j<=200;j++){
                if(dp[cnt][j]<dp[cnt][100]){
                    dp[cnt][100]=dp[cnt][j],preid[cnt][100]=preid[cnt][j],pre_v[cnt][100]=pre_v[cnt][j];
                }
            }
            now+=dp[cnt][100];
            if(now>a[i]){
                f=0;
                break;
            }
            int pos=100;
            while(cnt){
                //cout<<pos<<" "<<dp[cnt][pos]<<" "<<preid[cnt][pos]<<" "<<pre_v[cnt][pos]<<endl;
                if(preid[cnt][pos]) ans.push_back(preid[cnt][pos]);
                pos=pre_v[cnt--][pos];
            }
        }
        if(!f){
            puts("-1");
            continue;
        }
        printf("%d\n",ans.size());
        for(auto t:ans) printf("%d ",t);
        puts("");
    }
    return 0;
}
//unordered_map