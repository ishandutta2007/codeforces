#include<bits/stdc++.h>
using namespace std;
#define int long long
struct task{int st,tm,pri,id,cpy;}tsk[50001];
bool operator<(task a,task b){return a.st<b.st;}
int ed[50001],cpy_tm[50001],n,uk,final[50001];
struct cmp{bool operator()(int a,int b){return tsk[a].pri<tsk[b].pri;}};
int finish(){
	int i;
	for(i=1;i<=n;i++)tsk[i].tm=tsk[i].cpy;
	priority_queue<int,vector<int>,cmp> q;
	for(i=1;i<=n;i++){
//		cout<<i<<":";
		q.push(i);
		int gap=tsk[i+1].st-tsk[i].st;
		while(q.size()){
			int x=q.top();
//			cout<<x<<" ";
			if(tsk[x].tm<=gap)gap-=tsk[x].tm,q.pop(),ed[x]=tsk[i+1].st-gap;
			else{tsk[x].tm-=gap;break;}
		}
//		puts("");
	}
	return ed[uk];
}
signed main(){
	freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
	int i,fnshtm;cin>>n;
	for(i=1;i<=n;i++)cin>>tsk[i].st>>tsk[i].tm>>tsk[i].pri,tsk[i].cpy=tsk[i].tm,tsk[i].id=i;
	sort(tsk+1,tsk+n+1);tsk[n+1].st=1e18;
	for(i=1;i<=n;i++)if(tsk[i].pri==-1){uk=i;break;}
//	cout<<"uk="<<uk<<"\n";
	cin>>fnshtm;
	int lwb=1,upb=1e9,mid;
	while(true){
		int mid=lwb+upb>>1,fnsh;
		tsk[uk].pri=mid;
		fnsh=finish();
		if(fnsh<fnshtm)upb=mid;
		else if(fnsh==fnshtm){
			cout<<mid<<"\n";
			for(i=1;i<=n;i++)final[tsk[i].id]=ed[i];
			for(i=1;i<=n;i++)cout<<final[i]<<" ";
			return 0;
		}
		else lwb=mid;
	}
}
/*1
3
4 3 -1
0 2 2
1 3 3
7
*/
/*2
3
3 1 2
2 3 3
3 1 -1
4
*/