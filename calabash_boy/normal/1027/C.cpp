//
// Created by calabash_boy on 18-7-6.
//
#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB(x) push_back(x)
#define debug(x) cerr<<"[debug] "<<#x<<":"<<x<<endl;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
const int maxn = 1e6+100;
const int MOD = 1e9+7;
int a[maxn],n;
map<int,int> cnt;
vector<int> ans;
bool cmp(int x,int y){
    return x>y;
}
void solve(){
    scanf("%d",&n);
    cnt.clear();
    ans.clear();
    while (n--){
        int len;
        scanf("%d",&len);
        cnt[len] ++;
        if (cnt[len] == 2){
            ans.push_back(len);
            cnt[len] = 0;
        }
    }
    sort(ans.begin(),ans.end(),cmp);
    int w = -1,h = -1;
    for (int i=0;i<ans.size()-1;i++){
        if (w == -1 && h == -1){
            w = ans[i];
            h = ans[i+1];
        }else if (1ll*w*ans[i+1]> 1LL*h *ans[i]){
            w = ans[i];
            h = ans[i+1];
        }
    }
    printf("%d %d %d %d\n",w,w,h,h);
}
int main(){
    int T;
    for (scanf("%d",&T);T;T--){
        solve();
    }

    return 0;
}