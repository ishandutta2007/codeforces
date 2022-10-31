//
// Created by calabash_boy on 18-7-6.
//
#include<bits/stdc++.h>
#define F first
#define S second
#define PB(x) push_back(x)
#define debug(x) cout<<"[debug] "<<#x<<":"<<x<<endl;
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
const int MOD = -1;
const int maxn = 25;
LL a[maxn][maxn];
map<LL,int> Cnt1,Cnt2;
int n,m;
LL k;
LL ans;
void brute_forward(int x,int y,LL now){
    now^= a[x][y];
    if (x==1&&y==1){
        Cnt1[now]++;
        return;
    }
    if (x>1){
        brute_forward(x-1,y,now);
    }
    if (y>1){
        brute_forward(x,y-1,now);
    }
}
void brute_backward(int x,int y,LL now){
    now^= a[x][y];
    if (x==n&&y==m){
        Cnt2[now]++;
        return ;
    }
    if (x<n){
        brute_backward(x+1,y,now);
    }
    if (y<m){
        brute_backward(x,y+1,now);
    }
}
void calc(int x,int y){
    LL K = k^a[x][y];
    for (auto x:Cnt1){
        ans+=1LL*x.second*Cnt2[K^x.first];
    }
}
int main(){
    cin>>n>>m>>k;
    for (int i=1;i<=n;i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    int len = m+n-2;
    len/=2;
    for (int i=1;i<=n;i++){
        int j = len+2-i;
        if (j<=0||j>m)continue;
        Cnt1.clear();
        Cnt2.clear();
        brute_forward(i,j,0);
        brute_backward(i,j,0);
        calc(i,j);
    }
    cout<<ans<<endl;
    return 0;
}