/*
 * @Author: BilyHurington
 * @Date: 2021-05-02 22:36:28
 * @LastEditors: BilyHurington
 * @LastEditTime: 2021-05-02 22:56:04
 */
#include<bits/stdc++.h>
#ifdef LOCAL_TEST
#include<ctime>
#endif
using namespace std;
int T,n,m,x,ans[100010];
pair<int,int> A[100010];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
void solve(){
    scanf("%d %d %d",&n,&m,&x);
    for(int i=1;i<=n;i++) scanf("%d",&A[i].first),A[i].second=i;
    sort(A+1,A+n+1);
    for(int i=n;i>n-m;i--) pq.push(make_pair(A[i].first,i-(n-m))),ans[A[i].second]=i-(n-m);
    for(int i=n-m;i>=1;i--){
        pair<int,int> P=pq.top();pq.pop();
        ans[A[i].second]=P.second;P.first+=A[i].first;
        pq.push(P);
    }
    while(pq.size()) pq.pop();puts("YES");
    for(int i=1;i<=n;i++) printf("%d ",ans[i]);puts("");
}
int main(){
    #ifdef LOCAL_TEST
    clock_t start=clock();
    #endif
    scanf("%d",&T);
    while(T--) solve();
    #ifdef LOCAL_TEST
    clock_t end=clock();cout<<endl;
    cout<<"The program costs "<<(double)(end-start)/CLOCKS_PER_SEC<<" seconds"<< endl;
    puts("");system("pause");
    #endif
    return 0;
}