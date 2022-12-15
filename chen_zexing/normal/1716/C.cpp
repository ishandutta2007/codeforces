#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
int a[3][200005];
int t[3][200005];
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int n;
        cin>>n;
        for(int i=1;i<=2;i++)
            for(int j=1;j<=n;j++)
                scanf("%d",&a[i][j]),a[i][j]+=a[i][j]!=0;
        for(int i=n;i>=1;i--){
            if(i==n) t[1][i]=max(a[1][i]+1,a[2][i]),t[2][i]=max(a[2][i]+1,a[1][i]);
            else{
                t[1][i]=max({a[1][i]+(n-i)*2+1,t[1][i+1]+1,a[2][i]});
                //t[1][i]=min(t[1][i],max(max(a[1][i]+1,a[2][i])+(n-i)*2,t[2][i+1]));
                t[2][i]=max({a[2][i]+(n-i)*2+1,t[2][i+1]+1,a[1][i]});
                //t[2][i]=min(t[2][i],max(max(a[2][i]+1,a[1][i])+(n-i)*2,t[1][i+1]));
            }
            //cout<<t[1][i]<<" "<<t[2][i]<<endl;
        }
        for(int i=n-1;i;i--){
            t[1][i]=min(t[1][i],max(max(a[1][i]+1,a[2][i])+(n-i)*2,t[2][i+1]));
            t[2][i]=min(t[2][i],max(max(a[2][i]+1,a[1][i])+(n-i)*2,t[1][i+1]));
        }
        printf("%d\n",t[1][1]);
    }
    return 0;
}