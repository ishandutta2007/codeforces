#include <stdio.h>
#include<iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <map>
#include <stack>
#include <unordered_set>
#define hash hassh
using namespace std;
int f[200005],a[200005];
long long sum[2];
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n,tot=0;
        cin>>n;
        sum[0]=sum[1]=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            sum[i%2]+=a[i];
            f[i]=0;
        }
        a[n+1]=f[n+1]=0;
        for(int i=1;i<=n;i++) if(a[i]>a[i-1]+a[i+1]) f[i]=1,tot++;
        if(tot==0&&sum[0]==sum[1]){
            puts("YES");
            continue;
        }
        int fl=0;
        for(int i=1;i<n;i++){
            int temp=0,t=f[i-1]+f[i]+f[i+1]+f[i+2];
            swap(a[i],a[i+1]);
            for(int j=i-1;j<=i+2;j++) if(j>=1&&j<=n&&a[j]>a[j+1]+a[j-1]) temp++;
            //cout<<tot<<" "<<t<<" "<<temp<<" "<<i<<endl;
            //cout<<sum[0]<<" "<<sum[1]<<endl;
            //cout<<f[i-1]<<" "<<f[i]<<" "<<f[i+1]<<" "<<f[i+2]<<endl;
            if(tot-t+temp==0&&sum[i%2]-a[i+1]+a[i]==sum[(i+1)%2]-a[i]+a[i+1])
            {
                fl=1;
                break;
            }
            swap(a[i],a[i+1]);
        }
        if(fl) puts("YES");
        else puts("NO");
    }
    return 0;
}