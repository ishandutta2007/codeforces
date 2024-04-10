#pragma GCC optimize("Ofast,unroll-loops")
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
char t[200005];
vector<int> l,r;
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        scanf("%s",s+1);
        int n=strlen(s+1),cnt=0,cl=0,cr=0,ul=0,ur=0;
        l.clear(),r.clear();
        for(int i=1;i<=n;i++){
            if(s[i]=='?') cnt++;
            if(s[i]=='(') cl++;
            else cr++;
        }
        for(int i=1;i<=n;i++){
            if(s[i]=='('||s[i]==')') t[i]=s[i];
            else{
                if(cl==n/2) t[i]=')',ur++,r.push_back(i);
                else t[i]='(',cl++,ul++,l.push_back(i);
            }
        }
        if(ul&&ur){
            swap(t[l.back()],t[r[0]]);
            //cout<<l.back()<<" "<<r[0]<<endl;
            int pre=0,f=1;
            for(int i=1;i<=n;i++){
                if(t[i]=='(') pre++;
                else pre--;
                if(pre<0) f=0;
            }
            if(f) puts("NO");
            else puts("YES");
        }
        else puts("YES");
    }
    return 0;
}
//unordered_map
//cf