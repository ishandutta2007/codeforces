#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <set>
#include <ctime>

#define ll long long

using namespace std;

int arr1[200005],arr2[200005];
int w1[200005],w2[200005];

int main() {
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i) {
        scanf("%d",&arr1[i]);
        w1[arr1[i]]=i;
    }
    for(int i=0;i<n;++i) {
        scanf("%d",&arr2[i]);
        w2[arr2[i]]=i;
    }
    int cnt=0,last=-1;
    for(int i=0;i<n;++i) {
        if (w2[arr1[i]]>last) last=w2[arr1[i]],++cnt;
        else break;
    }
    printf("%d\n",n-cnt);
    return 0;
}