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
int a[100005];
int f[200005];
int main() {
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n*2+1;i++) f[i]=0;
        sort(a+1,a+n+1);
        for(int i=1;i<=n;i++){
            if(f[a[i]]) a[i]++,f[a[i]]=1;
            else f[a[i]]=1;
        }
        int ans=0;
        for(int i=1;i<=n*2+1;i++) ans+=f[i];
        cout<<ans<<endl;
    }
    return 0;
}