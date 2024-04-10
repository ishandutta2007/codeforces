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
#include <random>
using namespace std;
char s[200005];
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int a,b,c,d,n;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        scanf("%s",s+1),n=strlen(s+1);
        int ca=0,cb=0;
        for(int i=1;i<=n;i++) s[i]=='A'?ca++:cb++;
        if(a+c+d!=ca||b+c+d!=cb){
            puts("NO");
            continue;
        }
        int now=0,both=0;
        vector <int> bd,bc;
        for(int i=1;i<=n+1;i++){
            if(i!=n+1&&(i==1||s[i]!=s[i-1])) now++;
            else{
                both+=(now-1)/2;
                if(now%2==0) s[i-1]=='A'?bd.push_back(now/2):bc.push_back(now/2);
                now=1;
            }
        }
        int dif=c+d-both;
        if(dif<=0){
            puts("YES");
            continue;
        }
        sort(bd.begin(),bd.end()),sort(bc.begin(),bc.end());
        int pc=0,pd=0;
        while(dif){
            if(pc<bc.size()&&c>=bc[pc]) c-=bc[pc],dif--,pc++;
            else if(pd<bd.size()&&d>=bd[pd]) d-=bd[pd],dif--,pd++;
            else break;
        }
        puts(dif<=0?"YES":"NO");
    }
    return 0;
}