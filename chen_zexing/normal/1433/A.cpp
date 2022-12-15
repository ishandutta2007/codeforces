#include <stdio.h>
#include<iostream>
#include<string>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <map>
using namespace std;
int main() {
    int T;
    cin>>T;
    while(T--){
        int x;
        cin>>x;
        int t=x%10,ans=0,cnt=1;
        ans=(t-1)*10;
        while(x){
            x/=10;
            ans+=cnt;
            cnt++;
        }
        cout<<ans<<endl;
    }
    return 0;
}