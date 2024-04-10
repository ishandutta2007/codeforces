#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
#define A first
#define B second
template<typename T> int sz(const T &a){return int(a.size());}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string a,b;
        cin>>a>>b;
        if(a==b){
            printf("0\n");
            continue;
        }
        int flippeddiff=0;
        int notflippeddiff=0;
        int cnt[2][2];
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++)cnt[i][j]=0;
        }
        for(int i=0;i<n;i++){
            if(a[i]==b[i]){
                flippeddiff++;
                cnt[0][a[i]-'0']++;
            }
            if(a[i]!=b[i]){
                notflippeddiff++;
                cnt[1][a[i]-'0']++;
            }
        }
        int best=INT_MAX;
        if(flippeddiff%2==1){
            if(cnt[0][0]==cnt[0][1]||cnt[0][1]==cnt[0][0]+1){
                best=min(best,flippeddiff);
            }
        }
        if(notflippeddiff%2==0){
            if(cnt[1][0]==cnt[1][1]||cnt[1][1]==cnt[1][0]+1) {
                best = min(best, notflippeddiff);
            }
        }
        if(best==INT_MAX)printf("-1\n");
        else printf("%d\n",best);
    }
    return 0;
}