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
char s[100005];
int sum[100005];
map <int,int> a;
int main() {
    int T;
    cin >> T;
    while(T--)
    {
        a.clear();
        int n;
        long long ans=0;
        scanf("%d",&n);
        scanf("%s",s+1);
        for(int i=1;i<=n;i++) {
            int t=s[i]-'0';
            sum[i]=sum[i-1]+t;
        }
        for(int i=1;i<=n;i++)
        {
            sum[i]-=i;
            a[sum[i]]++;
        }
        a[0]++;
        //for(int i=1;i<=n;i++) cout<<sum[i]<<" ";
        cout<<endl;
        for(int i=-n;i<=sum[n]+n;i++)
            if(a[i]>=2) {
                long long k=a[i];
                ans += k*(k-1)/2;
            }
        printf("%lld\n",ans);
    }
    return 0;
}