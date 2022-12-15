#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
int cnt[500005];
int main(){
    int T = 1, kase = 0;
    //cin >> T;
    while (T--){
        int n,x;
        cin>>n>>x;
        for(int i=1,a;i<=n;i++) scanf("%d",&a),cnt[a]++;
        for(int i=1;i<x;i++){
            if(cnt[i]%(i+1)){
                puts("No");
                exit(0);
            }
            cnt[i+1]+=cnt[i]/(i+1);
        }
        puts("Yes");
    }
    return 0;
}