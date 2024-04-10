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
using namespace std;
int a[105],b[505],cnt[105];
int main() {
    int T;
    cin>>T;
    while(T--){
        int n,k;
        cin>>n>>k;
        vector <int> v;
        memset(cnt,0,sizeof(cnt));
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        int c=0;
        for(int i=1;i<=n;i++) cnt[a[i]]++;
        for(int i=1;i<=n;i++) if(cnt[i]) c++,v.push_back(i);
        if(c>k){
            puts("-1");
            continue;
        }
        printf("%d\n",n*k);
        for(int i=1;i<=n;i++){
            for(int j=0;j<k;j++) printf("%d ",v[j%v.size()]);
        }
        printf("\n");
    }
    return 0;
}