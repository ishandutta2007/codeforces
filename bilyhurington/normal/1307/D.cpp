/*
 * @Author: BilyHurington
 * @Date: 2020-02-13 19:20:46
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-02-18 00:37:18
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
int n,m,k,dis1[200010],dis2[200010],spl[200010];
vector<int> v[200010];
pair<int,int> val[200010];
bool vis[200010];
struct node{
	int pos,dis;
	bool operator <(const node &x)const{
		return x.dis<dis;
	}
};
priority_queue<node> q;
void dijk1(){
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++) dis1[i]=1e9;
	dis1[1]=0;
	q.push((node){1,0});
	while(!q.empty()){
		node p=q.top();
		q.pop();
		if(vis[p.pos]) continue;
		vis[p.pos]=true;
		for(int i=0;i<v[p.pos].size();i++){
			if(dis1[v[p.pos][i]]>dis1[p.pos]+1){
				dis1[v[p.pos][i]]=dis1[p.pos]+1;
				q.push((node){v[p.pos][i],dis1[v[p.pos][i]]});
			}
		}
	}
}
void dijk2(){
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++) dis2[i]=1e9;
	dis2[n]=0;
	q.push((node){n,0});
	while(!q.empty()){
		node p=q.top();
		q.pop();
		if(vis[p.pos]) continue;
		vis[p.pos]=true;
		for(int i=0;i<v[p.pos].size();i++){
			if(dis2[v[p.pos][i]]>dis2[p.pos]+1){
				dis2[v[p.pos][i]]=dis2[p.pos]+1;
				q.push((node){v[p.pos][i],dis2[v[p.pos][i]]});
			}
		}
	}
}
int s[200010],top;
int main(){
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=k;i++) scanf("%d",&spl[i]);
    int x,y;
    while(m--){
        scanf("%d %d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dijk1();
    dijk2();
    // for(int i=1;i<=n;i++) printf("%d %d\n",dis1[i],dis2[i]);
    for(int i=1;i<=k;i++) val[i]=make_pair(dis1[spl[i]],dis2[spl[i]]);
    sort(val+1,val+k+1);
    s[top=1]=1;
    int ans=0;
    // for(int i=1;i<=k;i++) printf("%d %d\n",val[i].first,val[i].second);
    for(int i=2;i<=k;i++){
        int l=1,r=top,mid;
        while(l+1<r){
            mid=(l+r)/2;
            if(val[s[mid]].first+val[i].second<val[s[mid]].second+val[i].first) l=mid;
            else r=mid;
        }
        // printf("%d %d\n",l,r);
        for(int j=l;j<=r;j++) ans=max(ans,min(val[s[j]].first+val[i].second,val[s[j]].second+val[i].first)+1);
        while(top>0&&val[s[top]].second<val[i].second) top--;
        s[++top]=i;
    }
    printf("%d\n",min(ans,dis1[n]));
    return 0;
}