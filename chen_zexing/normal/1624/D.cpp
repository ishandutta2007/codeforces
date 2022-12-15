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
using namespace std;
char s[200005];
int cnt[26],c[26];
int main() {
    int T = 1;
    cin >> T;
    while(T--) {
        int n,k;
        memset(cnt,0,sizeof(cnt));
        scanf("%d%d",&n,&k);
        scanf("%s",s+1);
        for(int i=1;i<=n;i++) cnt[s[i]-'a']++;
        int l=1,r=n/k;
        while(l<r){
            int mid=(l+r)/2+1;
            int two=0,one;
            for(int i=0;i<26;i++) two+=cnt[i]/2;
            one=n-two;
            //cout<<one<<" "<<two<<endl;
            if(two>=mid/2*k&&one>=mid%2*k) l=mid;
            else r=mid-1;
        }
        printf("%d\n",l);
    }
    return 0;
}