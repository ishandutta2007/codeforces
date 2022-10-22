#include<bits/stdc++.h>
using namespace std;
int stu,bug,flim,dif[100002],abi[100001],fc[100001],ord[100001],doneby[100001],did[100001];
vector<int> add[100001];//[1]bug
struct cmp0{
	inline bool operator()(int x,int y){
		if(did[x])return false;if(did[y])return true;
		return fc[x]>fc[y];
	}
};
bool cdt(int dlim){
	int f=0;
	fill(did+1,did+stu+1,0);
	priority_queue<int,vector<int>,cmp0> q;
	for(int i=1;i<=bug;i++){
		int x=ord[i];
		for(int j=0;j<add[i].size();j++)q.push(add[i][j]);
		while(q.size()&&did[q.top()]==dlim)q.pop();
		if(q.empty())return false;
		int cpy;
		if(did[q.top()])doneby[x]=q.top(),did[q.top()]++;
		else cpy=q.top(),doneby[x]=cpy,did[cpy]=1,f+=fc[cpy],q.pop(),q.push(cpy);
		if(f>flim)return false;
	}
	return true;
}
inline bool cmp(int x,int y){return dif[x]>dif[y];}
int main(){
	int i;
	scanf("%d%d%d",&stu,&bug,&flim);
	for(i=1;i<=bug;i++)scanf("%d",dif+i);
	for(i=1;i<=stu;i++)scanf("%d",abi+i);
	for(i=1;i<=stu;i++)scanf("%d",fc+i);
	for(i=1;i<=bug;i++)ord[i]=i;
	sort(ord+1,ord+bug+1,cmp);
//	for(i=1;i<=bug;i++)cout<<ord[i]<<" ";puts("");
	for(i=1;i<=stu;i++)
		dif[bug+1]=abi[i],add[lower_bound(ord+1,ord+bug+1,bug+1,cmp)-ord].push_back(i);
//	for(i=1;i<=bug;i++){for(int j=0;j<add[i].size();j++)cout<<add[i][j]<<" ";puts("");}
	int lwb=0,upb=100000,mid;
	while(upb-lwb>1){
		mid=lwb+upb>>1;
//		cout<<lwb<<" "<<upb<<":"<<mid<<"\n";
		cdt(mid)?upb=mid
		:lwb=mid;
	}
//	cout<<upb<<"\n";
	if(cdt(upb)){
		puts("YES");
		for(i=1;i<=bug;i++)cout<<doneby[i]<<" ";
	}
	else puts("NO");
	return 0;
}
/*1
3 4 9
1 3 1 2
2 1 3
4 3 6
*/
/*2
3 4 10
2 3 1 2
2 1 3
4 3 6
*/
/*3
3 4 9
2 3 1 2
2 1 3
4 3 6
*/
/*4
3 4 5
1 3 1 2
2 1 3
5 3 6
*/