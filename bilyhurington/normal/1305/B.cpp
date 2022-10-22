/*
 * @Author: BilyHurington
 * @Date: 2020-02-13 19:20:46
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-03-03 22:50:54
 */
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<queue>
using namespace std;
int n;
char s[1010];
bool vis[1010];
vector<int> vec;
vector<vector<int> > ans;
int main(){
    scanf("%s",s+1);
    n=strlen(s+1);
    for(int i=1;i<=n;i++){
        int l=1,r=n;
        vec.clear();
        while(1){
            while(l<=n&&(vis[l]||s[l]==')')) l++;
            while(r>=1&&(vis[r]||s[r]=='(')) r--;
            if(l>r||l==n+1||r==0) break;
            vec.push_back(l);
            vec.push_back(r);
            vis[l]=vis[r]=1;
        }
        if(!vec.size()) break;
        sort(vec.begin(),vec.end());
        ans.push_back(vec);
    }
    printf("%d\n",ans.size());
    for(int i=0;i<ans.size();i++){
        printf("%d\n",ans[i].size());
        for(int j=0;j<ans[i].size();j++) printf("%d ",ans[i][j]);
        printf("\n");
    }
    return 0;
}