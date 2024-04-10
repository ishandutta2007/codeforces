#include <bits/stdc++.h>
using namespace std;


int n;
int c[26];
bool dp[14][(1<<14)][25];
int kol;
inline bool cmp(int a,int b){
    return a>b;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) {
        cin>>c[i];
        if (c[i]==1) {
            ++kol;
        } else if (c[i]==2) {
            cout<<"NO";
            return 0;
        }
    }
    sort(c+1,c+n+1,cmp);
    if ((n+1)/2>kol) {
        cout<<"NO";
        return 0;
    }
    n-=kol;
    if (n==0 && kol==1) {
        cout<<"YES";
        return 0;
    }
    dp[1][0][kol]=true;
    for (int i=1;i<n;++i) {
        for (int j=0;j<(1<<(n-i));++j) {
            for (int k=0;k<=kol;++k) if (dp[i][j][k]) {
                int mm=((1<<(n-i))-1)^j;
                for (int msk=mm;;msk=(msk-1)&mm) {
                    int kol2=1;
                    int kol3=0;
                    for (int z=0;z<n-i && kol2<=c[i];++z)
                        if (msk&(1<<z)) kol2+=c[i+1+z],kol3++;
                    if (kol2>c[i] || kol2+k<c[i]) {
                        if (msk==0) break;
                        continue;
                    }
                    int msk2=(msk^j);
                    if ((msk2&1) && kol3+c[i]-kol2>=2) { dp[i+1][msk2/2][k-c[i]+kol2]=true;}
                    if (msk==0) break;
                }
            }
        }
    }
    cout<<(dp[n][0][c[n]-1] ? "YES" : "NO");
}