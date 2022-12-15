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
    ios::sync_with_stdio(false);
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        string s,now="",ans="z";
        int pos;
        cin>>s;
        for(int i=1;i<=n;i++){
            now="";
            for(int j=i-1;j<n;j++) now+=s[j];
            if((n-i+1)%2) for(int j=i-2;j>=0;j--) now+=s[j];
            else for(int j=0;j<=i-2;j++) now+=s[j];
            if(now<ans) ans=now,pos=i;
        }
        cout<<ans<<endl;
        cout<<pos<<endl;
    }
    return 0;
}