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
int main() {
    int T=1;
    cin>>T;
    while(T--){
        string s;
        cin>>s;
        int f1=0,sum=0,c=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0') f1=1;
            sum+=s[i]-'0';
            if((s[i]-'0')%2==0) c++;
        }
        if(f1&&c>=2&&sum%3==0) puts("red");
        else puts("cyan");
    }
    return 0;
}