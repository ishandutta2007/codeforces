#include <stdio.h>
#include<iostream>
#include<string>
#include <algorithm>
#include <string.h>
#include <vector>
#include <cmath>
#include <map>
#include <unordered_map>
using namespace std;
int a[105],cnt[105];
int main() {
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        memset(cnt,0,sizeof(cnt));
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),cnt[a[i]]++;
        int ans=0,f1=0,f2=0;
        for(int i=0;i<=100;i++)
        {
            if(cnt[i]<2&&f2==0) ans+=i,f2=1;
            if(cnt[i]<1&&f1==0) ans+=i,f1=1;
            if(f1&&f2) break;
        }
        cout<<ans<<endl;
    }
    return 0;
}