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
int a[100005],lst[100005],fst[100005];
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n,k,ans=0;
        cin>>n>>k;
        for(int i=1;i<=k;i++) scanf("%d",&a[i]),lst[a[i]]=i;
        for(int i=k;i>=1;i--) fst[a[i]]=i;
        for(int i=1;i<=n;i++){
            if(lst[i]==0) ans++,ans+=i<n,ans+=i>1;
            else{
                if(i<n&&lst[i+1]<=fst[i]) ans++;
                if(i>1&&lst[i-1]<=fst[i]) ans++;
            }
            //cout<<ans<<endl;
        }
        cout<<ans<<endl;
    }
    return 0;
}
//
/// 
//01
//