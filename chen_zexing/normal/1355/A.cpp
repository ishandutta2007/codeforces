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
        long long a,k;
        cin>>a>>k;
        k--;
        while(k--){
            long long mn=10,mx=-1;
            long long t=a;
            while(t){
                mn=min(mn,t%10);
                mx=max(mx,t%10);
                t/=10;
            }
            if(mn==0) break;
            else a+=mn*mx;
        }
        cout<<a<<endl;
    }
    return 0;
}