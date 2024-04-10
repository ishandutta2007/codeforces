#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <memory.h>
#include <string>
#include <set>
#include <map>

using namespace std;

int cnt9(long long x) {
    int ret=0;
    while(x%10==9) x/=10,ret++;
    return ret;
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    long long p,d;
    cin >> p >> d;
    long long ans=p; int cnt=cnt9(ans);
    long long num=0,tmp;
    for(int i=0;num<p;++i) {
        if (num<=(p-9)/10) num=num*10+9;
        else break;
        if (num<=p) if (cnt9(num)>cnt&&(p-num)<=d||cnt9(num)==cnt&&(p-num)<=d&&num>ans) cnt=cnt9(num),ans=num;
    }
    tmp=p/10;
    int m9=1;
    while(tmp) {
        num=(tmp-1);
        for(int i=0;i<m9;++i) num=num*10+9;
        m9++; tmp/=10;
        if (cnt9(num)>cnt&&(p-num)<=d||cnt9(num)==cnt&&(p-num)<=d&&num>ans) cnt=cnt9(num),ans=num;
    }
    cout << ans << endl;
    return 0;
}