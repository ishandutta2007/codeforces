#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<bitset>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#define pb push_back
using namespace std;
vector<int>d[20];
int ma;
void f(int ll,int rr,int now){
    if(ll==rr)return;
    int mm=(ll+rr)/2;
    ma=max(ma,now);
    for(int i=ll;i<=mm;i++)d[now].pb(i);
    f(ll,mm,now+1);
    f(mm+1,rr,now+1);
}
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int i,j,k,n;
    scanf("%d",&n);
    f(1,n,1);
    printf("%d\n",ma);
    for(i=1;i<=ma;i++){
        printf("%d",d[i].size());
        for(j=0;j<d[i].size();j++)printf(" %d",d[i][j]);
        puts("");
    }
    return 0;
}