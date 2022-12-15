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
using namespace std;
int main() {
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        int ans=1<<n;
        for(int i=1;i<n/2;i++) ans+=1<<i;
        for(int i=n/2;i<n;i++) ans-=1<<i;
        cout<<ans<<endl;
    }
    return 0;
}