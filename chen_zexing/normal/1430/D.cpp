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
char s[200005];
vector <int> v;
int main() {
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        scanf("%s",s+1);
        v.clear();
        int cnt=1;
        for(int i=2;i<=n+1;i++){
            if(i==n+1||s[i]!=s[i-1]) v.push_back(cnt),cnt=1;
            else cnt++;
        }
        int ans=0,left=0,use=0;
        for(int i=0;i<v.size();i++) left+=v[i]-1;
        int i;
        for(i=0;i<v.size();i++){
            if(!left) break;
            if(v[i]>1){
                ans++;
                if(use>=v[i]-1){
                    use-=(v[i]-1);
                    use++;
                    left--;
                }
                else if(use==v[i]-2){
                    use=0;
                    left--;
                }
                else{
                    left-=(v[i]-1-use);
                    use=0;
                }
            }
            else{
                ans++;
                left--;
                use++;
            }
        }
        printf("%d\n",ans+(v.size()-ans+1)/2);
    }
    return 0;
}