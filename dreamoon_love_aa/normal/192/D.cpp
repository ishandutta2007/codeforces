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
#include<queue>
#define pb push_back
using namespace std;
#define SIZE 100010
struct data{
    int x;
    data(int _x){x=_x;}
    bool operator<(const data& cc)const{return x>cc.x;}
};
priority_queue<data>H1;
int a[SIZE],cnt,k;
long long b,now;
bool go(int x){
    now+=x;
    bool res=(now>b);
    cnt++;
    H1.push(data(x));
    if(cnt>=k){
        cnt--;
        now-=H1.top().x;
        H1.pop();
    }
    //printf("[%I64d]",now);
    return res;
}
int main(){
    int i,j,n,an;
    scanf("%d%d",&n,&k);
    an=n;
    cin>>b;
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(i=n-1;i>=1;i--){
        if(go(a[i]))an=min(an,i);
    }
    printf("%d\n",an);
    return 0;
}