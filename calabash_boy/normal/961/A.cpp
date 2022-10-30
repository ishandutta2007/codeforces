#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3+100;
int a[maxn],n,m;
int main(){
    scanf("%d%d",&n,&m);
    int ans =0;
    for (int i=0;i<m;i++){
        int temp;
        scanf("%d",&temp);
        a[temp]++;
        int score = 0x3f3f3f3f;
        for (int j=1;j<=n;j++){
            score = min(score,a[j]);
        }
        ans+=score;
        for (int j=1;j<=n;j++){
            a[j]-=score;
        }
    }
    cout<<ans<<endl;
    return 0;
}