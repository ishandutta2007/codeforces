#include <stdio.h>
#include<iostream>
#include<string>
#include <string.h>
#include <algorithm>
#include <map>
#include <cmath>
#include <unordered_map>
using namespace std;
int a[100005],cnt[100];
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        long long ans=0;
        cin>>n;
        memset(cnt,0,sizeof(cnt));
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++){
            int t=0;
            while(a[i]){
                a[i]/=2;
                t++;
            }
            cnt[t]++;
        }
        for(int i=1;i<=50;i++) ans+=1LL*cnt[i]*(cnt[i]-1)/2;
        cout<<ans<<endl;
    }
    return 0;
}