#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <assert.h>
#include <algorithm>
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
using namespace std;
int a[105];
int main() {
    int T = 1;
    cin >> T;
    while(T--) {
        int n,m,k,f=1;
        cin>>n>>m>>k;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<n;i++){
            if(a[i]>=max(a[i+1]-k,0)){
                m+=a[i]-max(a[i+1]-k,0);
            }
            else{
                m-=max(a[i+1]-k,0)-a[i];
                if(m<0){
                    f=0;
                    break;
                }
            }
        }
        puts(f?"YES":"NO");
    }
    return 0;
}
//
/// 
//01
// 
//
//dp
//