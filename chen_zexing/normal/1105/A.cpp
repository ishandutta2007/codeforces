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
int a[1005];
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        int ans=INT_MAX,p;
        for(int i=1;i<=100;i++){
            int tot=0;
            for(int j=1;j<=n;j++){
                if(a[j]>i) tot+=a[j]-i-1;
                else if(a[j]<i) tot+=i-a[j]-1;
            }
            ans=min(ans,tot);
            if(ans==tot) p=i;
        }
        cout<<p<<" "<<ans<<endl;
    }
    return 0;
}