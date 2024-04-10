#include<bits/stdc++.h>
using namespace std;

int n;
int a[4005];
bool dp[2005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--){
        cin>>n;
        n<<=1;
        int p=0;
        vector<int> v;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(a[i]>a[p]){
                v.emplace_back(1);
                p=i;
            }else v.back()++;
        }
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(int &cur:v){
            for(int i=(n>>1)-cur;i>=0;i--){
                dp[i+cur]|=dp[i];
            }
        }
        cout<<(dp[n>>1]?"YES\n":"NO\n");
    }

    return 0;
}