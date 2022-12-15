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
int cnt[1000005],c;
unordered_map<int,int>mp;
int f=1;
vector <int> ans;
int main() {
    int T=1;
    //cin>>T;
    while(T--){
        int n;
        cin>>n;
        int lst=0;
        for(int i=1;i<=n&&f;i++){
            scanf("%d",&a[i]);
            if(a[i]>0){
                if(mp[a[i]]){
                    if(c==0) mp.clear(),ans.push_back(i-lst),lst=i;
                    else f=0;
                }
                else{
                    mp[a[i]]=1;
                    cnt[a[i]]++;
                    c++;
                }
            }
            else{
                a[i]=-a[i];
                if(cnt[a[i]]){
                    cnt[a[i]]--,c--;
                    if(c==0) mp.clear(),ans.push_back(i-lst),lst=i;
                }
                else f=0;
            }
        }
        if(c) f=0;
        if(f){
            printf("%d\n",ans.size());
            for(int i=0;i<ans.size();i++) printf("%d ",ans[i]);
        }
        else puts("-1");
    }
    return 0;
}