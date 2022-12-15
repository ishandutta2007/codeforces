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
int a[100005],b[100005],c[100005];
vector <int> v;
int main() {
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++) scanf("%d",&b[i]),c[i]=b[i]-a[i];
        int f=1,cnt=0;
        for(int i=1;i<=n;i++){
            if(c[i]<0) f=0;
        }
        v.clear();
        for(int i=1;i<=n;i++)
        {
            if(c[i]>0&&(i==1||c[i]!=c[i-1])) cnt++;
            if(c[i]>0) v.push_back(c[i]);
        }
        sort(v.begin(),v.end());
        if(v.size()&&v[0]!=v[v.size()-1]) f=0;
        if(f==0||cnt>1) puts("NO");
        else puts("YES");
    }
    return 0;
}