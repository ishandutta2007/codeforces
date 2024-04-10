#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <assert.h>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <time.h>
#include <map>
#include <stack>
#include <unordered_set>
#include <bitset>
#define hash hassh
using namespace std;
char s[200005];
int a[15];
int main() {
    int T = 1;
    //cin >> T;
    while(T--) {
        int n;
        cin>>n;
        scanf("%s",s+1);
        for(int i=1;i<=n;i++){
            if(s[i]=='L'){
                for(int j=0;j<10;j++)
                    if(a[j]==0){
                        a[j]=1;
                        break;
                    }
            }
            else if(s[i]=='R'){
                for(int j=9;j>=0;j--)
                    if(a[j]==0){
                        a[j]=1;
                        break;
                    }
            }
            else a[s[i]-'0']=0;
        }
        for(int i=0;i<10;i++) cout<<a[i];
    }
    return 0;
}
//
/// 
//01
// 
//
//dp
//