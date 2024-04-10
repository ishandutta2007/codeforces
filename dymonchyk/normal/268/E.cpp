#include <cstdio>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <ctime>

using namespace std;

int n;
pair <int,int> arr[50005];

bool cmp(const pair <int,int> & a,const pair <int,int> & b) {
    return a.first*a.second*(100-b.second)>b.first*b.second*(100-a.second);
//  return a.first*a.second>b.first*b.second||
//      a.first*a.second==b.first*b.second&&a.second>b.second;
}

int main() {
//  freopen("input.txt","r", stdin);
//  freopen("output.txt", "w", stdout);
    scanf("%d",&n);
    for(int i=0;i<n;++i) {
        scanf("%d%d",&arr[i].first,&arr[i].second);
    }
    sort(arr,arr+n,cmp);
    double len=0,like=0;
    for(int i=0;i<n;++i) {
        len+=(1.0*(100-arr[i].second)*like)/100+arr[i].first;
        like+=0.01*arr[i].second*arr[i].first;
    }
    printf("%.12lf\n",len);
    return 0;
}