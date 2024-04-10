#include <stdio.h>
#include<iostream>
#include<string>
#include <algorithm>
#include <string.h>
#include <vector>
#include <cmath>
#include <map>
#include <unordered_map>
#define LL long long
#define MAX 100005

using namespace std;
unordered_map <long long,int> mp;
int main() {
    int n,t,ans=0;
    long long sum=0;
    cin>>n;
    mp[0]=1;
    for(int i=1;i<=n;i++){
        scanf("%d",&t);
        sum+=t;
        if(mp[sum]){
            mp.clear();
            ans++;
            sum=t;
            mp[sum]=mp[0]=1;
        }
        else mp[sum]=1;
    }
    printf("%d\n",ans);
    return 0;
}