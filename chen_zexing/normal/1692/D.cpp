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
int gcd(int x,int y){
    return y==0?x:gcd(y,x%y);
}
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        string s;
        int x,ans=0;
        cin>>s;
        cin>>x;
        x=gcd(x,1440);
        int now=(s[0]-'0')*600+(s[1]-'0')*60+(s[3]-'0')*10+s[4]-'0',st=now;
        do{
            int a=now/60,b=now%60;
            if(a/10==b%10&&a%10==b/10) ans++;
            now+=x;
            if(now>=1440) now-=1440;
        }
        while(now!=st);
        cout<<ans<<endl;
    }
    return 0;
}
//cf