#include <bits/stdc++.h>
using namespace std;



int n,k;
string s[105];
int dp1[105][105];
int dp2[105][105];

int ans,posx,posy;

inline bool check1(int x,int y,int z) {
    for (int i=x;i<=y;++i)
        if (s[i][z]=='#') return false;
    return true;
}

inline bool check2(int x,int y,int z) {
    for (int i=y;i<=z;++i)
        if (s[x][i]=='#') return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    for (int i=1;i<=n;++i) {
        cin>>s[i];
        s[i]="#"+s[i];
        for (int j=1;j<=n;++j) {
            dp1[i][j]=dp1[i-1][j];
            if (i>=k && check1(i-k+1,i,j)) dp1[i][j]++;
            dp2[i][j]=dp2[i][j-1];
            if (j>=k && check2(i,j-k+1,j)) dp2[i][j]++;
        }
    }
    ans=-1;
    posx=1;
    posy=1;
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=n;++j) {
            int cur=0;
            int x=i+k-1;
            x=min(x,n);
            cur+=dp1[x][j]-dp1[i-1][j];
            x=min(j+k-1,n);
            cur+=dp2[i][x]-dp2[i][j-1];
            if (cur>ans) {
                ans=cur;
                posx=i;
                posy=j;
            }
        }
    }
    cout<<posx<<" "<<posy;

}