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
#include <functional>
#define hash hassh
using namespace std;
long long ans[105];
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        long long a,b,m,f=0;
        cin>>a>>b>>m;
        if(a==b){
            printf("1 %lld\n",a);
            continue;
        }
        long long temp=a,nd=1;
        while(temp<b){
            //cout<<temp<<endl;
            if(b-temp>=(1LL<<(nd-1))&&b-temp<=m*(1LL<<(nd-1))){
                printf("%lld %lld ",nd+1,a),f=1;
                long long r=b-temp-(1LL<<(nd-1));
                for(int i=1;i<=nd;i++){
                    if(r/(1LL<<(max(0LL,nd-i-1)))>m-1) ans[i]=m,r-=(m-1)*(1LL<<(max(0LL,nd-i-1)));
                    else ans[i]=r/((1LL<<(max(0LL,nd-i-1))))+1,r%=(1LL<<(max(0LL,nd-i-1)));
                }
                long long pre=a;
                for(int i=1;i<=nd;i++) printf("%lld ",pre+ans[i]),pre+=pre+ans[i];
                puts("");
                break;
            }
            temp*=2,nd++;
        }
        if(!f) puts("-1");
    }
    return 0;
}
//
/// 
//01
//