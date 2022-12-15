#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <assert.h>
#include <algorithm>
#include <stdlib.h>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <time.h>
#include <map>
#include <stack>
#include <unordered_set>
#include <bitset>
#define hash hassh
#define li __int128_t
#define ull unsigned long long
using namespace std;
struct node{
    int a,id;
    friend bool operator <(node a,node b){
        return a.a<b.a;
    }
}a[200005];
int pref[200005],suff[200005],pred[200005],sufd[200005];
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i].a),a[i].id=i;
        sort(a+1,a+n+1);
        pref[0]=suff[n+1]=1;
        for(int i=1;i<=n;i++){
            if(!pref[i-1]) continue;
            if(i==1) pref[i]=1;
            else if(i==2) pref[i]=1,pred[i]=a[i].a-a[i-1].a;
            else{
                int d=a[i].a-a[i-1].a;
                if(d==pred[i-1]) pref[i]=1,pred[i]=pred[i-1];
            }
        }
        for(int i=n;i>=1;i--){
            if(!suff[i+1]) continue;
            if(i==n) suff[i]=1;
            else if(i==n-1) suff[i]=1,sufd[i]=a[i+1].a-a[i].a;
            else{
                int d=a[i+1].a-a[i].a;
                if(d==sufd[i+1]) suff[i]=1,sufd[i]=sufd[i+1];
            }
        }
        for(int i=1;i<=n;i++){
            if(i==1){
                if(suff[i+1]){
                    printf("%d\n",a[i].id);
                    exit(0);
                }
            }
            else if(i==n){
                if(pref[i-1]){
                    printf("%d\n",a[i].id);
                    exit(0);
                }
            }
            else if(i==2){
                if(pref[i-1]&&suff[i+1]&&sufd[i+1]==a[i+1].a-a[i-1].a){
                    printf("%d\n",a[i].id);
                    exit(0);
                }
            }
            else if(i==n-1){
                if(pref[i-1]&&suff[i+1]&&pred[i-1]==a[i+1].a-a[i-1].a){
                    printf("%d\n",a[i].id);
                    exit(0);
                }
            }
            else{
                if(pref[i-1]&&suff[i+1]&&pred[i-1]==a[i+1].a-a[i-1].a&&sufd[i+1]==a[i+1].a-a[i-1].a){
                    printf("%d\n",a[i].id);
                    exit(0);
                }
            }
        }
        puts("-1");
    }
    return 0;
}
//
/// 
//01
//