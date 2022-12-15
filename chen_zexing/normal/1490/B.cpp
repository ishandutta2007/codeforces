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
int a[30005];
int main() {
    int T=1;
    cin>>T;
    while(T--){
        int c[3]={};
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++){
            c[a[i]%3]++;
        }
        int nd=n/3,ans=0;
        while(c[0]>nd||c[1]>nd||c[2]>nd){
            for(int i=0;i<3;i++)
                if(c[i]>nd){
                    c[(i+1)%3]+=c[i]-nd;
                    ans+=c[i]-nd;
                    c[i]=nd;
                }
        }
        cout<<ans<<endl;
    }
    return 0;
}