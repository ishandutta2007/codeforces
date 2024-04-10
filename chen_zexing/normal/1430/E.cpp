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
char s[200005];
int a[200005];
stack <int> v[26];
int tree[200005];
void add(int x){
    while(x<=200000){
        tree[x]++;
        x+=x&-x;
    }
}
int query(int x){
    int ans=0;
    while(x){
        ans+=tree[x];
        x-=x&-x;
    }
    return ans;
}
int main() {
    int n;
    long long ans=0;
    cin>>n;
    scanf("%s",s+1);
    for(int i=1;i<=n;i++) v[s[i]-'a'].push(i);
    for(int i=1;i<=n;i++) a[n-i+1]=v[s[i]-'a'].top(),v[s[i]-'a'].pop();
    for(int i=1;i<=n;i++) add(a[i]),ans+=i-query(a[i]);
    printf("%lld\n",ans);
    return 0;
}