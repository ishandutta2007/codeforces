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
char s[105];
long long a[105];
unordered_map<long long ,int> mp;
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n,m;
        cin>>n>>m;
        mp.clear();
        for(int i=1;i<=n;i++){
            scanf("%s",s+1);
            long long temp=0;
            for(int j=1;j<=m;j++) temp=temp*2+s[j]-'0';
            mp[temp]=1;
            a[i]=temp;
        }
        long long l=0,r=(1LL<<m)-1;
        long long tar=(r-n)>>1;
        while(l<r){
            long long mid=(l+r)>>1;
            int cnt=0;
            for(int i=1;i<=n;i++)
                if(a[i]<mid)
                    cnt++;
            long long tot=mid-cnt;
            //cout<<cnt<<" "<<mid<<" "<<tot<<endl;
            if(tot<tar) l=mid+1;
            else r=mid;
        }
        while(mp[l]) l++;
        //cout<<l<<endl;
        for(int i=m-1;i>=0;i--)
            printf("%d",(l&(1LL<<i))>0);
        puts("");
    }
    return 0;
}