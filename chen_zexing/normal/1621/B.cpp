#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <climits>
#include <algorithm>
#include <complex>
#include <string.h>
using namespace std;
int l[100005],r[100005],c[100005];
int main() {
    int T = 1;
    cin >> T;
    while(T--) {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d%d%d",&l[i],&r[i],&c[i]);
        int mx=0,mn=INT_MAX,mxpos=0,mnpos=0,same=INT_MAX,f=0;
        for(int i=1;i<=n;i++){
            if(l[i]<mn) mn=l[i],mnpos=i,f=0;
            else if(l[i]==mn&&c[i]<c[mnpos]) mnpos=i;
            if(r[i]>mx) mx=r[i],mxpos=i,f=0;
            else if(r[i]==mx&&c[i]<c[mxpos]) mxpos=i;
            if(l[i]==mn&&r[i]==mx){
                if(f) same=min(same,c[i]),f=1;
                else same=c[i],f=1;
            }
            if(f) printf("%d\n",min(same,c[mnpos]+c[mxpos]));
            else printf("%d\n",c[mnpos]+c[mxpos]);
        }
    }
    return 0;
}