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
int a[200005];
map <int,int> cnt,lst;
int ccnt[200005],suf[200005];
int main() {
    int T=1;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        cnt.clear();
        for(int i=1;i<=n;i++) ccnt[i]=0;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),cnt[a[i]]++,lst[a[i]]=i;
        for(int i=1;i<=n;i++) if(i==lst[a[i]]) ccnt[cnt[a[i]]]++;
        suf[n+1]=0;
        for(int i=n;i>=1;i--) suf[i]=suf[i+1]+ccnt[i];
        int ans=0;
        for(int i=1;i<=n;i++) ans=max(ans,suf[i]*i);
        cout<<n-ans<<endl;
    }
    return 0;
}