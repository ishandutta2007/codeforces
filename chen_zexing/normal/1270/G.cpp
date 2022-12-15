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
int a[1000005];
vector <int> v;
int f[1000005];
int main() {
    int T;
    cin>>T;
    while(T--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]),f[i]=0;
        //v.clear();
        v.push_back(1);
        f[1]=v.size();
        int now=1-a[1];
        int pre=1;
        while(!f[now]){
            v.push_back(now);
            f[now]=f[pre]+1;
            pre=now;
            now-=a[now];
        }
        printf("%d\n",f[pre]-f[now]+1);
        for(int i=f[now]-1;i<v.size();i++) printf("%d ",v[i]);
        puts("");
    }
    return 0;
}