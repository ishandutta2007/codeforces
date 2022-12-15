#include <stdio.h>
#include<iostream>
#include<string>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
#include <map>
using namespace std;
int a[2005],b[2005],c[2005];
long long ans[205][205][205];
bool cmp(int a,int b)
{
    return a<b;
}
long long search(int x,int y,int z)
{
    if(ans[x][y][z]) return ans[x][y][z];
    long long cnt=0;
    if(x&&y) cnt=max(cnt,search(x-1,y-1,z)+a[x]*b[y]);
    if(y&&z) cnt=max(cnt,search(x,y-1,z-1)+b[y]*c[z]);
    if(x&&z) cnt=max(cnt,search(x-1,y,z-1)+c[z]*a[x]);
    return ans[x][y][z]=cnt;
}
int main() {
    int T=1;
    //cin >> T;
    while(T--)
    {
        int A,B,C;
        cin>>A>>B>>C;
        for(int i=1;i<=A;i++) scanf("%d",&a[i]);
        for(int i=1;i<=B;i++) scanf("%d",&b[i]);
        for(int i=1;i<=C;i++) scanf("%d",&c[i]);
        sort(a+1,a+A+1,cmp);
        sort(b+1,b+B+1,cmp);
        sort(c+1,c+C+1,cmp);
        printf("%lld\n",search(A,B,C));
    }
    return 0;
}