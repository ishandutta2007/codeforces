#include<bits/stdc++.h>
#define maxn 53
#define INF 1e17
#define E 1e-7
#define A first
#define B second
using namespace std;
double dp[maxn][maxn][maxn];
int n;
pair<int,int> a[maxn];
bool check(double x){
    for(int i=0;i<=n+1;i++){
        for(int j=0;j<=n+1;j++){
            for(int k=0;k<=n+1;k++){
                dp[i][j][k]=INF;
            }
        }
    }
    dp[0][0][0]=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=i;j++){
            for(int k=0;k<=i;k++){
                if(a[i].A<a[i-1].A){
                    if(j-k+1>=0)dp[i][j][0]=min(dp[i][j][0],dp[i-1][j-k+1][k]);
                    if(j-k>=0)dp[i][j][1]=min(dp[i][j][1],dp[i-1][j-k][k]+a[i].A-x*a[i].B);
                } else 
				if(k-1>=0)dp[i][j][k]=min(dp[i-1][j+1][k],dp[i-1][j][k-1]+a[i].A-x*a[i].B);
                else dp[i][j][k]=dp[i-1][j+1][k];
                }
            }
        }
    for(int j=0;j<=n;j++)
        for(int k=0;k<=n-j;k++) if(dp[n][j][k]<=0)return 1;
    return 0;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i].A);
    for(int i=1;i<=n;i++)scanf("%d",&a[i].B);
    sort(a+1,a+n+1,greater<pair<int,int> >());
    a[0].A=-1050000000;
    double l=0,r=5e9,mid;
    while(fabs(r-l)>E){
        mid=(l+r)/2;
		//printf("l:%.15lf r:%.15lf mid:%.15lf\n",l,r,mid);
        if(check(mid))r=mid;
        else l=mid;
    }
    double ans=mid*1000;
    cout<<(ans-(long long)ans<1e-4?(long long)ans:(long long)ans+1)<<endl;
    return 0;
}