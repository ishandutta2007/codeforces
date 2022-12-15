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
    long long v,cnt;
};
vector <fac> v;
int main() {
    int T;
    cin>>T;
    while(T--){
        long long n;
        cin>>n;
        v.clear();
        long long t=n;
        for(long long i=2;i*i<=n;i++)
        {
            if(n%i==0){
                int c=0;
                while(n%i==0) n/=i,c++;
                v.push_back(fac{i,c});
            }
            //cout<<i<<endl;
        }
        if(n>1) v.push_back(fac{n,1});
        long long mx=0,p=0;
        for(int i=0;i<v.size();i++)
            if(v[i].cnt>mx){
                mx=v[i].cnt;
                p=v[i].v;
            }
        printf("%lld\n",mx);
        long long now=1;
        for(int i=1;i<mx;i++) printf("%lld ",p),now*=p;
        printf("%lld\n",t/now);
    }
    return 0;
}