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
int a[200005],cnt[200005];
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n;
        int mx=0,c=0;
        cin>>n;
        for(int i=1;i<=n;i++) cnt[i]=0;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),cnt[a[i]]++;
        for(int i=1;i<=n;i++) mx=max(mx,cnt[i]),c+=cnt[i]>0;
        if(mx>c) cout<<c<<endl;
        else if(mx==c) cout<<(c-1)<<endl;
        else cout<<mx<<endl;
    }
    return 0;
}