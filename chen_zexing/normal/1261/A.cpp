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
char s[2005];
struct node{
    int l,r;
};
vector <node> ans;
int main() {
    int T=1;
    cin>>T;
    while(T--){
        int n,k;
        cin>>n>>k;
        scanf("%s",s+1);
        int f;
        ans.clear();
        for(int i=1;i<=n;i++){
            if(i<=(k-1)*2) f=i%2;
            else f=(i<=n/2+k-1);
            if(f){
                if(s[i]=='(') continue;
                else{
                    int p;
                    for(int j=i+1;j<=n;j++)
                        if(s[j]=='('){
                            p=j;
                            break;
                        }
                    ans.push_back(node{i,p});
                    for(int j=i;j<=(i+p)/2;j++) swap(s[j],s[p-(j-i)]);
                }
            }
            else{
                if(s[i]==')') continue;
                else{
                    int p;
                    for(int j=i+1;j<=n;j++)
                        if(s[j]==')'){
                            p=j;
                            break;
                        }
                    ans.push_back(node{i,p});
                    for(int j=i;j<=(i+p)/2;j++) swap(s[j],s[p-(j-i)]);
                }
            }
        }
        printf("%d\n",ans.size());
        for(int i=0;i<ans.size();i++)
            printf("%d %d\n",ans[i].l,ans[i].r);
    }
    return 0;
}