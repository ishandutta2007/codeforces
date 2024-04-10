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
unordered_map<long long,char>mp;
set <long long> s1,s2;
int main() {
    int T=1;
    //cin>>T;
    while(T--){
        int n,m;
        cin>>n>>m;
        while(m--){
            char c;
            while(scanf("%c",&c)&&c!='+'&&c!='-'&&c!='?');
            if(c=='+'){
                int a,b;
                char t;
                scanf("%d %d %c",&a,&b,&t);
                mp[1LL*n*a+b]=t;
                if(mp[1LL*n*b+a]>='a'&&mp[1LL*n*b+a]<='z'){
                    if(mp[1LL*n*b+a]==t) s1.insert(1LL*min(a,b)*n+max(a,b));
                    else s2.insert(1LL*min(a,b)*n+max(a,b));
                }
            }
            else if(c=='-'){
                int a,b;
                scanf("%d %d",&a,&b);
                if(mp[1LL*n*b+a]>='a'&&mp[1LL*n*b+a]<='z'){
                    if(mp[1LL*n*b+a]==mp[1LL*n*a+b]) s1.erase(s1.find(1LL*min(a,b)*n+max(a,b)));
                    else s2.erase(s2.find(1LL*min(a,b)*n+max(a,b)));
                }
                mp[1LL*n*a+b]='|';
            }
            else{
                int a;
                scanf("%d",&a);
                if(a%2){
                    puts(s1.size()||s2.size()?"YES":"NO");
                }
                else puts(s1.size()?"YES":"NO");
            }
        }
    }
    return 0;
}