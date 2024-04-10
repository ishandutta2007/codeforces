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
int main() {
    int T=1;
    cin>>T;
    while(T--){
        int n,t;
        cin>>n>>t;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        int ans=0,mx=0,pos,now=0;
        long long sum=0;
        for(int i=1;i<=n;i++){
            sum+=a[i];
            if(a[i]>mx){
                mx=a[i],pos=i;
            }
            if(sum<=t) ans=max(ans,i);
            else{
                if(sum-mx<=t){
                    if(ans<i-1){
                        now=pos;
                        ans=i-1;
                    }
                }
                else break;
            }
        }
        cout<<now<<endl;
    }
    return 0;
}