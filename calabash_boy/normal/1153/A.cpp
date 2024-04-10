#include <bits/stdc++.h>
using namespace std;
const int maxn = 100;
int n,t;
int main(){
    int ans_id = -1;
    int ans = INT_MAX;
    scanf("%d%d",&n,&t);
    for (int i=1;i<=n;i++){
        int s,d;
        scanf("%d%d",&s,&d);
        if (s >= t){
            if (s < ans){
                ans = s;
                ans_id = i;
            }
        }else{
            s = s + (t-s + d-1)/d*d;
            if (s < ans){
                ans = s;
                ans_id = i;
            }
        }
    }
    cout<<ans_id<<endl;
    return 0;
}