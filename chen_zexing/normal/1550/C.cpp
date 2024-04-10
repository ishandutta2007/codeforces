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
int a[200005];
int main() {
    int T = 1;
    cin >> T;
    while (T--){
        int n,ans=0;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=4&&i+j-1<=n;j++){
                if(j==1||j==2){
                    ans++;
                    continue;
                }
                else{
                    int f=1;
                    for(int k=i;k<=i+j-1;k++)
                        for(int l=k+1;l<=i+j-1;l++)
                            for(int m=l+1;m<=i+j-1;m++)
                                if(a[m]>=a[l]&&a[l]>=a[k]||a[m]<=a[l]&&a[l]<=a[k])
                                    f=0;
                    ans+=f;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}