#include <bits/stdc++.h>

using namespace std;

int P[20];

int n,l,r,x;

int BF(int now,int sum,int minval,int maxval)
{
    if(sum > r) return 0;
    if(now == n){
        if(sum >= l && maxval-minval >= x) return 1;
        else return 0;
    }

    return BF(now+1, sum+P[now], min(minval,P[now]), max(maxval,P[now]))+BF(now+1, sum, minval, maxval);
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    scanf("%d %d %d %d",&n,&l,&r,&x);

    int i;
    for(i=0; i<n; i++) scanf("%d",P+i);

    printf("%d\n",BF(0,0,2147483647,0));

    return 0;
}