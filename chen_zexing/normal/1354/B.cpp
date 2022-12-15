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
char s[200005];
struct pp{
    int v,l;
};
vector <pp> v;
int main() {
    int T;
    cin>>T;
    while(T--){
        scanf("%s",s);
        int l=strlen(s);
        v.clear();
        int cnt=1;
        for(int i=1;i<=l;i++){
            if(i==l||s[i]!=s[i-1]){
                v.push_back(pp{s[i-1]-'0',cnt});
                cnt=1;
            }
            else cnt++;
        }
        int mn=999999;
        for(int i=0;i<v.size();i++){
            if(i+2>=v.size()) break;
            int c[5]={};
            for(int j=i;j<=i+2;j++) c[v[j].v]++;
            if(c[1]==1&&c[2]==1&&c[3]==1){
                mn=min(mn,v[i+1].l+2);
            }
        }
        if(mn!=999999) printf("%d\n",mn);
        else puts("0");
    }
    return 0;
}