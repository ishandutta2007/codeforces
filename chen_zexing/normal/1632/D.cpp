#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <climits>
#include <algorithm>
#include <complex>
#include <string.h>
#include <iomanip>
#include <assert.h>
using namespace std;
int a[200005],st[200005][20];
int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n,ans=0;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),st[i][0]=a[i];
        for(int i=1;i<=19;i++)
            for(int j=1;j<=n;j++)
                st[j][i]=gcd(st[j][i-1],st[max(1,j-(1<<(i-1)))][i-1]);
        for(int i=1,pos=1;i<=n;i++){
            int now=i,v=a[i],f=0;
            while(now>=pos&&i-v+1<=now){
                int temp=now;
                for(int j=19;j>=0;j--) if(gcd(v,st[now][j])==v&&max(1,now-(1<<j)+1)>=pos) now=max(1,now-(1<<j)+1);
                if(i-v+1<=temp&&i-v+1>=now&&i-v+1>=pos){
                    f=1;
                    break;
                }
                v=gcd(v,a[now-1]),now--;
            }
            if(f) ans++,pos=i+1;
            printf("%d ",ans);
        }
    }
    return 0;
}
//unordered_map