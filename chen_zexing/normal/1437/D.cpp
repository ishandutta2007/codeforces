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
using namespace std;
int a[200005];
int main() {
    int T;
    cin>>T;
    while(T--){
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        int cnt=1,ans=1,now=1,sum=0;
        for(int i=2;i<=n;i++){
            if(a[i]>a[i-1]){
                sum++;
            }
            else{
                if(now<cnt){
                    now++;
                    sum++;
                }
                else{
                    cnt=sum;
                    ans++;
                    sum=1;
                    now=1;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}