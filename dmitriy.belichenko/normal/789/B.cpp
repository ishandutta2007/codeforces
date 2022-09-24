#include <stdio.h>
#include <set>
#include<iostream>
using namespace std;

#define abs(x) ((x) > (-(x)) ? (x) : (-(x)))

int main() {
    long long b, q, l, m;
    set<long long> a;
    long long t;
    long long cnt;
    int i;
    
    scanf("%lld %lld %lld %lld", &b, &q, &l, &m);
    for(i = 0; i < m; i++) {
        scanf("%lld", &t);
        if(abs(t) <= l) a.insert(t);
    }
    
    if(abs(b) > l) {
        printf("0");
        return 0;
    }
    if(b == 0) {
        if(a.find(0) != a.end()) printf("0");
        else printf("inf");
        return 0;
    }
    if(q == 0) {
        if(a.find(0) != a.end()) {
            if(a.find(b) != a.end()) printf("0");
            else printf("1");
        }
        else printf("inf");
        return 0;
    }
    if(q == 1) {
        if(a.find(b) != a.end()) printf("0");
        else printf("inf");
        return 0;
    }
    if(q == -1) {
        if(a.find(b) != a.end() && a.find(-b) != a.end()) printf("0");
        else printf("inf");
        return 0;
    }
    
    cnt = 0;
    for(t = b; abs(t) <= l; t *= q) if(a.find(t) == a.end()) cnt++;
    printf("%lld", cnt);
    
    return 0;
}