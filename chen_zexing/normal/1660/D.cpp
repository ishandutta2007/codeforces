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
#include <iomanip>
#include <assert.h>
using namespace std;
int sig[200005],pre[200005],a[200005],c0[200005];
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int n,mx=0,ll=0,rr;
        cin>>n;
        sig[0]=1,rr=n;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            if(a[i]==2||a[i]==-2) pre[i]=pre[i-1]+1;
            else pre[i]=pre[i-1];
            if(a[i]<0) sig[i]=-sig[i-1];
            else sig[i]=sig[i-1];
            c0[i]=c0[i-1]+(a[i]==0);
        }
        int l1=0,l_1=0;
        for(int i=1;i<=n;i++){
            if(a[i]==0) continue;
            if(sig[i]==1) {
                while (c0[l1] != c0[i]) l1++;
                while (sig[l1] != sig[i]) l1++;
                if(pre[i]-pre[l1]>mx) mx=pre[i]-pre[l1],ll=l1,rr=n-i;
            }
            else{
                while(c0[l_1]!=c0[i]) l_1++;
                while(sig[l_1]!=sig[i]) l_1++;
                if(pre[i]-pre[l_1]>mx) mx=pre[i]-pre[l_1],ll=l_1,rr=n-i;
            }
            //cout<<"#"<<i<<" "<<l<<endl;
            //if(pre[i]-pre[l]>mx) mx=pre[i]-pre[l],ll=l,rr=n-i;
        }
        printf("%d %d\n",ll,rr);
    }
    return 0;
}
//unordered_map