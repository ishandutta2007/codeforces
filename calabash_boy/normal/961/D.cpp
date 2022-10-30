#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+100;
int n;
int x[maxn],y[maxn];
int flag[maxn];
bool oneline(int xx,int yy,int zz){
    int x1 = x[yy]-x[xx];
    int y1 = y[yy]-y[xx];
    int x2 = x[zz]-x[xx];
    int y2 = y[zz]-y[xx];
    return 1LL*x1*y2==1LL*x2*y1;
}
bool check(int xx,int yy){
    memset(flag,0,sizeof flag);
    flag[xx]=flag[yy]=1;
    for (int i=0;i<n;i++){
        if (i==xx||i==yy)continue;
        if (oneline(xx,yy,i))flag[i]=1;
    }
    int rest1=-1,rest2=-1;
    for (int i=0;i<n;i++){
        if (flag[i]==0){
            if (rest1==-1){
                rest1=i;
            }else if (rest2==-1){
                rest2=i;
            }else{
                break;
            }
        }
    }
    if (rest1==-1||rest2==-1)return true;
    xx = rest1;yy=rest2;
    flag[xx]=2;
    flag[yy]=2;
    for (int i=0;i<n;i++){
        if (i==xx||i==yy||flag[i]==1)continue;
        if (oneline(xx,yy,i))flag[i]=2;
    }
    for (int i=0;i<n;i++){
        if (flag[i]==0)return false;
    }
    return true;
}
int main(){
    scanf("%d",&n);
    if (n<=4){
        cout<<"YES"<<endl;
        return 0;
    }
    for (int i=0;i<n;i++){
        scanf("%d%d",x+i,y+i);
    }
    if (check(0,1)||check(0,2)||check(1,2)){
        cout<<"YES"<<endl;
        return 0;
    }
    cout<<"NO"<<endl;
    return 0;
}