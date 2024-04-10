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
long long mul[250005];
int main() {
    int T=1;
    //cin>>T;
    while(T--){
        int n,p;
        cin>>n>>p;
        long long ans=0;
        mul[0]=1;
        for(int i=1;i<=n;i++) mul[i]=mul[i-1]*i%p;
        for(int i=1;i<=n;i++){
            long long temp=i;
            temp*=n-i+1,temp%=p;
            temp*=mul[i],temp%=p;
            temp*=mul[n-i],temp%=p;
            ans+=temp,ans%=p;
        }
        cout<<ans<<endl;
    }
    return 0;
}