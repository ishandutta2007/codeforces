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
multiset <int,greater<int>> a,b;
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int n,f=1;
        cin>>n;
        a.clear(),b.clear();
        for(int i=1,x;i<=n;i++) scanf("%d",&x),a.insert(x);
        for(int i=1,x;i<=n;i++) scanf("%d",&x),b.insert(x);
        while(a.size()&&b.size()){
            if(*a.begin()<*b.begin()){
                int temp=*b.begin();
                b.erase(b.begin());
                b.insert(temp/2);
            }
            else if(*a.begin()==*b.begin()){
                a.erase(a.begin()),b.erase(b.begin());
            }
            else{
                int temp=*a.begin();
                if(temp%2){
                    f=0;
                    break;
                }
                else{
                    a.erase(a.begin());
                    a.insert(temp/2);
                }
            }
        }
        puts(f?"YES":"NO");
    }
    return 0;
}
//unordered_map