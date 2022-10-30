
#include<bits/stdc++.h>
using namespace std;
const int maxn = 105;
char mp[4][maxn][maxn];
int ans[4][2];
int n;
void calc(int x,int flag){
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            int temp = (i+j)%2;
            if (temp==0)temp = flag;
            else temp = 1-flag;
            ans[x][flag]+=(mp[x][i][j]!=temp+'0');
        }
    }
}
int calcAns(int x,int y){
    int res1 = 0;
    int res2 = 0;
    for (int i=0;i<4;i++){
        if (i==x||i==y){
            res1+=ans[i][0];
            res2+=ans[i][1];
        }else{
            res1+=ans[i][1];
            res2+=ans[i][0];
        }
    }
    return min(res1,res2);
}
int main(){
    scanf("%d",&n);
    for (int i=0;i<4;i++){
        for (int j=0;j<n;j++){
            scanf("%s",mp[i][j]);
        }
    }
    for (int i=0;i<4;i++){
        for (int j=0;j<=1;j++){
            calc(i,j);
        }
    }
    int res =0x3f3f3f3f;
    for (int i=0;i<4;i++){
        for (int j=0;j<4;j++){
            if (i!=j){
                res = min(res,calcAns(i,j));
            }
        }
    }
    cout<<res<<endl;
    return 0;
}