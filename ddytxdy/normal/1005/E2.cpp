#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=2e5+50;
int n,m,a[N],num[N*2];
LL solve(int x){
    LL ret=0;memset(num,0,sizeof(num));num[n]=1;
    for(int i=1,now=0,dat=0;i<=n;i++){
        if(a[i]>=x)dat+=num[now+n],now++;
        else now--,dat-=num[now+n];
        num[now+n]++;ret+=dat;
    }
    return ret;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    cout<<solve(m)-solve(m+1);
    return 0;
}