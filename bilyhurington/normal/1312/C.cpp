/*
 * @Author: BilyHurington
 * @Date: 2020-02-13 19:20:46
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-03-09 22:50:54
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
int T,n,k,cnt;
long long a[40],b[60];
int main(){
    scanf("%d",&T);
    while(T--){
        priority_queue<long long,vector<long long>,less<long long> > q;
        scanf("%d %d",&n,&k);
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]),q.push(a[i]);
        cnt=0;
        b[0]=1;
        while(b[cnt]<=1e16){++cnt;b[cnt]=b[cnt-1]*k;}
        for(int i=cnt;i>=0;i--){
            long long tp=q.top();
            q.pop();
            if(b[i]<=tp) q.push(tp-b[i]);
            else q.push(tp);
        }
        if(q.top()==0) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}