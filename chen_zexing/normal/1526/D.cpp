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
#include <time.h>
#include <map>
#include <stack>
#include <unordered_set>
#define hash hassh
using namespace std;
char s[200005];
int b[200005];
vector <int> v[5];
unordered_map <char,int> mp;
int tree[200005],l;
void add(int x){
    while(x<=l) tree[x]++,x+=x&-x;
}
int query(int x){
    int ans=0;
    while(x) ans+=tree[x],x-=x&-x;
    return ans;
}
int r[5];
char tt[5]={'0','A','N','T','O'};
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        scanf("%s",s+1);
        mp['A']=1,mp['N']=2,mp['T']=3,mp['O']=4;
        l=strlen(s+1);
        for(int i=1;i<=4;i++) v[i].clear();
        for(int i=1;i<=l;i++) v[mp[s[i]]].push_back(i);
        int a[5]={0,1,2,3,4};
        long long mx=0;
        do{
            //for(int i=1;i<=4;i++) cout<<a[i]<<" ";puts("");
            int x=0;
            for(int i=1;i<=4;i++)
                for(int j=0;j<v[a[i]].size();j++)
                    b[++x]=v[a[i]][j];
            long long cnt=0;
            for(int i=1;i<=l;i++) add(b[i]),cnt+=query(l)-query(b[i]);
            if(cnt>=mx){
                mx=cnt;
                for(int i=1;i<=4;i++) r[i]=a[i];
            }
            for(int i=1;i<=l;i++) tree[i]=0;
        }
        while(next_permutation(a+1,a+5));
        for(int i=1;i<=4;i++)
            for(int j=0;j<v[r[i]].size();j++)
                printf("%c",tt[r[i]]);
        puts("");
    }
    return 0;
}
//
/// 
//01
// 
//
//dp