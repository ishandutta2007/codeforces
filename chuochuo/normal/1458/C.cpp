#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
int a[6][1005][1005],p[6],add[6],x[6],y[6],ans[1005][1005];
int _,n,m;
char s[100005];
int main(){
    cin >> _;
    while (_--){
        cin >> n >> m;
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++){
                cin >> a[0][i][j];
                a[0][i][j]--;
            }
        cin >> s;
        for (int i=0;i<6;i++) x[i]=y[i]=add[i]=0,p[i]=i;
        for (int i=0;i<n;i++)
        for (int j=0;j<n;j++){
            int k=a[0][i][j];
            a[1][i][k]=j;
            a[2][j][k]=i;
            a[3][j][i]=k;
            a[4][k][i]=j;
            a[5][k][j]=i;
        }
        for (int i=0;i<m;i++){
            if (s[i]=='L'){
                y[p[0]]--;
                y[p[5]]--;
                add[p[1]]--;
                add[p[4]]--;
                x[p[2]]--;
                x[p[3]]--;
            } else if (s[i]=='R'){
                y[p[0]]++;
                y[p[5]]++;
                add[p[1]]++;
                add[p[4]]++;
                x[p[2]]++;
                x[p[3]]++;
            } else if (s[i]=='U'){
                x[p[0]]--;
                x[p[1]]--;
                add[p[2]]--;
                add[p[5]]--;
                y[p[3]]--;
                y[p[4]]--;
            } else if (s[i]=='D'){
                x[p[0]]++;
                x[p[1]]++;
                add[p[2]]++;
                add[p[5]]++;
                y[p[3]]++;
                y[p[4]]++;
            } else if (s[i]=='I'){
                swap(p[0],p[1]);
                swap(p[2],p[5]);
                swap(p[3],p[4]);
            } else if (s[i]=='C'){
                swap(p[0],p[5]);
                swap(p[1],p[4]);
                swap(p[2],p[3]);
            }
        }
        int o=p[0];
        int rx=(x[o]%n+n)%n;
        int ry=(y[o]%n+n)%n;
        int ra=(add[o]%n+n)%n;
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++){
                ans[(i+rx)%n][(j+ry)%n]=(a[o][i][j]+ra)%n;
            }
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                printf("%d ",ans[i][j]+1);
            }
            puts("");
        }
    }
}