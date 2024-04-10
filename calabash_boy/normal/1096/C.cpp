#include <bits/stdc++.h>
using namespace std;
int ans [1000];
int main(){
    for (int i=3;i<=360;i++){
        // each 360/i
        for (int j=1;j<=i-2;j++){
            // now 360 * j / i
            if (360 * j % i == 0){
                int deg = 360 * j / i;
                if (!ans[deg]){
                    ans[deg] = i;
                }
            }
        }
    }
    int T;
    for (scanf("%d",&T);T;T--){
        int x;
        cin>>x;
        cout<<ans[x*2]<<endl;
    }
    return 0;
}