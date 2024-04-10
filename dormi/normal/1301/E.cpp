#include<bits/stdc++.h>
using namespace std;
map<char,int> re;
char arr[501][501];
int pre[501][501][5];
int pre2[501][501][501];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m,q;
    cin>>n>>m>>q;
    re['R']=1;
    re['G']=2;
    re['Y']=3;
    re['B']=4;
    int si=min(n,m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>arr[i][j];
            pre[i][j][re[arr[i][j]]]=1;
            for(int k=1;k<=4;k++){
                pre[i][j][k]+=pre[i][j-1][k]+pre[i-1][j][k]-pre[i-1][j-1][k];
            }
            for(int k=1;k<=si;k++){
                if(i-2*k>=0&&j-2*k>=0) {
                    if (pre[i][j][4] - pre[i - k][j][4] - pre[i][j - k][4] + pre[i - k][j - k][4] == k * k) {
                        if (pre[i - k][j][2] - pre[i - 2 * k][j][2] - pre[i - k][j - k][2] + pre[i - 2 * k][j - k][2] ==
                            k * k) {
                            if (pre[i][j - k][3] - pre[i - k][j - k][3] - pre[i][j - 2 * k][3] +
                                pre[i - k][j - 2 * k][3] == k * k) {
                                if (pre[i - k][j - k][1] - pre[i - 2 * k][j - k][1] - pre[i - k][j - 2 * k][1] +
                                    pre[i - 2 * k][j - 2 * k][1] == k * k) {
                                    pre2[i][j][k]+=1;
                                }
                            }
                        }
                    }
                }
                pre2[i][j][k]+=pre2[i][j-1][k]+pre2[i-1][j][k]-pre2[i-1][j-1][k];
            }
        }
    }
    int a,b,c,d;
    while(q--){
        cin>>a>>c>>b>>d;
        bool work=false;
        for(int k=si;k>=1;k--){
            if(a-2+2*k<=b&&c-2+2*k<=d) {
                if (pre2[b][d][k] - pre2[a - 2 + 2 * k][d][k] - pre2[b][c - 2 + 2 * k][k] +
                    pre2[a - 2 + 2 * k][c - 2 + 2 * k][k] > 0) {
                    printf("%d\n", k * k * 4);
                    work = true;
                    break;
                }
            }
        }
        if(!work)printf("%d\n",0);
    }
    return 0;
}