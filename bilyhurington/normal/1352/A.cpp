/*
 * @Author: BilyHurington
 * @Date: 2020-02-13 19:20:46
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-05-09 22:43:16
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
int T,n;
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        vector<pair<int,int> > ans;
        for(int i=0;n;i++){
            if(n%10) ans.push_back(make_pair(n%10,i));
            n/=10;
        }
        printf("%d\n",ans.size());
        for(int i=0;i<ans.size();i++){
            int tmp=ans[i].first;
            for(int j=1;j<=ans[i].second;j++) tmp*=10;
            printf("%d ",tmp);
        }
        printf("\n");
    }
    return 0;
}