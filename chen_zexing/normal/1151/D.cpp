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
long long a[100005],b[100005];
int id[100005],n;
bool cmp(int x,int y){
    return a[x]-b[x]>a[y]-b[y];
}
int main() {
    cin>>n;
    for(int i=1;i<=n;i++) scanf("%lld%lld",&a[i],&b[i]),id[i]=i;
    sort(id+1,id+n+1,cmp);
    long long ans=0;
    for(int i=1;i<=n;i++) ans+=b[i]*n-a[i];
    for(int i=1;i<=n;i++) ans+=1LL*i*(a[id[i]]-b[id[i]]);
    cout<<ans<<endl;
    return 0;
}