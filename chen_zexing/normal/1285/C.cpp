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
struct fac{
    long long v,cnt,tot;
};
vector <fac> v;
int main() {
    int T=1;
    //cin>>T;
    while(T--){
        long long n,o;
        cin>>n;
        o=n;
        for(int i=2;1LL*i*i<=n;i++){
            if(n%i==0){
                int temp=0;
                long long t=1;
                while(n%i==0){
                    n/=i;
                    temp++;
                    t*=i;
                }
                v.push_back(fac{i,temp,t});
            }
        }
        if(n>1) v.push_back(fac{n,1,n});
        int l=v.size();
        long long ans=LLONG_MAX;
        long long p1,p2;
        for(int i=0;i<(1<<l);i++){
            long long multi=1;
            for(int j=0;j<l;j++)
                if((1<<j)&i)
                    multi*=v[j].tot;
            ans=min(ans,max(multi,o/multi));
            if(ans==max(multi,o/multi)) p1=multi,p2=o/multi;
        }
        cout<<p1<<" "<<p2<<endl;
    }
    return 0;
}