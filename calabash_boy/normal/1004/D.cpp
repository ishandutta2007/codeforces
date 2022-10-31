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
const int maxn = 1e6+100;
const int MOD = -1;
int a[maxn];
int cnt[maxn];
int t;
int maxDis =-1;
int maxCnt=0;
int Cnt[maxn];
inline int dis(int x1,int y1,int x2,int y2){
    return abs(x1-x2)+abs(y1-y2);
}
inline int num(int x){
    return 4*x;
}
bool check(int n,int m,int x,int y){
   // cout<<"here"<<endl;
    if(x<1||y<1||x>n||y>m)return false;
    for (int i=1;i<=maxDis;i++){
        Cnt[i]=0;
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            Cnt[dis(i,j,x,y)]++;
        }
    }
    for (int i=1;i<=maxDis;i++){
        if (Cnt[i]!=cnt[i])return false;
    }
    printf("%d %d\n%d %d\n",n,m,x,y);
    return true;
}
int main(){
    scanf("%d",&t);
    for (int i=0;i<t;i++){
        scanf("%d",a+i);
        cnt[a[i]]++;
        maxDis= max(maxDis,a[i]);
    }
    if (cnt[0]!=1){
        return puts("-1"),0;
    }
    maxCnt=cnt[maxDis];
    int tt=0;
    while (tt<maxDis){
        if (num(tt+1)==cnt[tt+1])tt++;
        else{
            break;
        }
    }
    int x =tt+1;
   // debug(x);
    for (int n = 1+2*tt;n<=t;n++){
        if (t%n!=0)continue;

        int m = t/n;
       // debug(n);
       // debug(m);
        int y = maxDis+1+x-n;
       // debug(x);debug(y);
        if (x-1==n-x){
            if (check(n,m,x,y))return 0;
        }else{
            if (dis(n,m,x,y)<maxDis&&maxCnt==1||dis(n,m,x,y)==maxDis&&maxCnt==2){
                if (check(n,m,x,y))return 0;
            }
        }
    }
    return puts("-1"),0;
}