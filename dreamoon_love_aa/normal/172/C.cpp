#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<bitset>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#define pb push_back
using namespace std;
#define SIZE 100000
long long a[SIZE],an[SIZE],b[SIZE];
vector<pair<int,int> >d;
int main(){
    int i,j,k,n,m;
    long long now=0;
    cin>>n>>m;
    for(i=0;i<n;i++)cin>>a[i]>>b[i];
    for(i=0;i<n;i++){
        d.pb(make_pair(b[i],i));
        if(i%m==m-1||i==n-1){
            now=max(now,a[i]);
            sort(d.begin(),d.end());
            int last=0;
            for(j=0;j<d.size();j=k){
                long long cnt=0;
                for(k=j;k<d.size()&&d[k].first==d[j].first;k++)cnt++;
                now+=d[j].first-last;
                last=d[j].first;
                for(int kk=j;kk<k;kk++){
                    an[d[kk].second]=now;
                }
                now+=(1+cnt/2);
            }
            now+=d.back().first;
            d.clear();
        }
    }
    for(i=0;i<n;i++){
        if(i)putchar(' ');
        printf("%d",an[i]);
    }
    puts("");
    return 0;
}