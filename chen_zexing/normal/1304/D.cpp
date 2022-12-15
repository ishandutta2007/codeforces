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
#define hash hassh
using namespace std;
char s[200005];
vector <int> v;
int main() {
    int T;
    cin>>T;
    while(T--){
        int n;
        scanf("%d %s",&n,s+1);
        v.clear();
        int cnt=1;
        for(int i=2;i<=n;i++)
        {
            if(s[i]!=s[i-1]||i==n) v.push_back(cnt),cnt=1;
            else cnt++;
        }
        int l=n,f=(s[1]=='>'),x=0;
        while(l>0){
            cnt=v[x++];
            if(!f) cnt++;
            else cnt--;
            if(x==1&&f) cnt++;
            if(x==v.size()&&f) cnt++;
            //cout<<cnt<<endl;
            if(f) for(int i=l;i>=l-cnt+1;i--) printf("%d ",i);
            else for(int i=l-cnt+1;i<=l;i++) printf("%d ",i);
            l-=cnt;
            f=1-f;
        }
        printf("\n");
        l=1,f=(s[1]=='>'),x=0;
        while(l<=n){
            cnt=v[x++];
            if(!f) cnt--;
            else cnt++;
            if(x==1&&!f) cnt++;
            if(x==v.size()&&!f) cnt++;
            if(!f) for(int i=l;i<=l+cnt-1;i++) printf("%d ",i);
            else for(int i=l+cnt-1;i>=l;i--) printf("%d ",i);
            l+=cnt;
            f=1-f;
        }
        printf("\n");
    }
    return 0;
}