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
long long a[200005],w;
vector <long long> v,v2;
int main() {
    int T;
    cin>>T;
    while(T--){
        int n;
        scanf("%d%lld",&n,&w);
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
        int f=0,p=0;
        for(int i=1;i<=n;i++)
            if(a[i]>=ceil(w/2.0)&&a[i]<=w)
            {
                f=1;
                p=i;
                break;
            }
        if(f){
            printf("1\n%d\n",p);
            continue;
        }
        v.clear();
        v2.clear();
        long long sum=0;
        for(int i=1;i<=n;i++){
            if(a[i]<ceil(w/2.0)){
                sum+=a[i];
                v.push_back(i);
            }
        }
        if(sum<ceil(w/2.0)){
            puts("-1");
            continue;
        }
        int cnt=0;
        sum=0;
        for(int i=0;i<v.size();i++) {
            if (sum >= ceil(w / 2.0))
                break;
            cnt++;
            sum+=a[v[i]];
            v2.push_back(v[i]);
        }
        printf("%d\n",cnt);
        for(int i=0;i<v2.size();i++) printf("%d ",v2[i]);
        printf("\n");
    }
    return 0;
}