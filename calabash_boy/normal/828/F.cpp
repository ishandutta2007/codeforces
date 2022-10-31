#include<bits/stdc++.h>
using namespace std;
#define MAXN 200005
const int INF =  0x3f3f3f3f; 
struct Edge{
	int start,des,length,id;
//	bool operator <(Edge* a){
//		return (des<a->des);
//	}
	bool operator < (const Edge& rhs) const { return length < rhs.length; }
};
Edge allE[MAXN];
vector <Edge> E[MAXN];
vector <Edge> remainE;
int father[MAXN];
int fa [MAXN][20];
int maxLength [MAXN][20];
int depth [MAXN];
int ans [MAXN];
int n,m;
int upperE[MAXN];
int link [MAXN];
int cheat;
//int upperLength[MAXN];
int findFather (int x){
	return father[x]==x?x:father[x] = findFather (father[x]);
}
void buildTree(int nod,int dad,int deep){
	depth[nod] = deep;
	for (vector<Edge>::iterator it = E[nod].begin();it!=E[nod].end();it++){
		if (it->des==dad){
			continue;
		}
		fa[it->des][0] = nod;
		upperE[it->des] = it->id;
		maxLength[it->des][0] = it->length; 
		buildTree(it->des,nod,deep+1);
	}
}
int lca(int a,int b){
	if (a==b){
		return a;
	}
	if (depth[a]<depth[b]){
		swap(a,b);
	}
	for (int i=18;i>=0;i--){
		if (fa[a][i]!=0&&depth[fa[a][i]]>=depth[b]){
			a = fa[a][i];
		}
	}
	for (int i=18;i>=0;i--){
		if (a==b){
			return a;
		}
		if (fa[a][i]!=fa[b][i]){
			a = fa[a][i];
			b = fa[b][i];
		}
	}
	return fa[a][0];
}
void initST(){
//	for (int i=1;i<=n;i++){
//		if (upperE[i]!=0){
//			maxLength[i][0] = allE
//		}
//	}
	for (int i=1;i<18;i++){
		for (int j = 1;j<=n;j++){
			if (fa[j][i-1]!=0){
				fa[j][i] = fa[fa[j][i-1]][i-1];
				maxLength[j][i] = max(maxLength[j][i-1],maxLength[fa[j][i-1]][i-1]);				
			}
		}
	}
}
int maxQuery(int nod,int ca){
	int ans = 0;
	for (int i=18;i>=0;i--){
		if (fa[nod][i]!=0&&depth[fa[nod][i]]>=depth[ca]){
			ans = max(ans,maxLength[nod][i]);
			nod = fa[nod][i];
		}
	}
	return ans;
}
int adjust(int nod,int ca,int tempAns){
	if (depth[nod]<=depth[ca])return ca;
	ans[upperE[nod]] = min(ans[upperE[nod]],tempAns);
	link[nod] = adjust(link[fa[nod][0]],ca,tempAns);
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		int u,v,c;
		scanf("%d%d%d",&u,&v,&c);
		if (cheat==0){
			cheat = u;
		}
		Edge e;
		e.start = u,e.des = v,e.length = c,e.id = i;
		allE[i] = e;
	} 
	for (int i=1;i<=n;i++){
		father[i]=i;
		link[i]=i;
	}
	sort(allE+1,allE+m+1);
	for (int i=1;i<=m;i++){
		Edge e = allE[i];
		int a = e.start,b = e.des,c = e.length,id = e.id;
		int fa = findFather(a),fb = findFather(b);
		if (fa == fb){
			remainE.push_back(e);
		}else{
			Edge newE;
			newE.des=a,newE.length = c,newE.id = id;
			E[b].push_back(newE);
			newE.des = b;
			E[a].push_back(newE);
			father[findFather(a)] = findFather(b); 
		}
	}
//	for (vector<Edge>::iterator it = remainE.begin();it!=remainE.end();it++){
//		cout<<it->id<<endl;
//	}

	buildTree(1,0,1);
	for (int i=1;i<=m;i++){
		ans[i] = INF;
	}
	initST();
//	if (cheat==58480){
//		return 0;
//	}
//	for (int i=1;i<=n;i++){
//		cout<<"maxLength["<<i<<"][1]="<<maxLength[i][1]<<endl;
//	}
	for (vector<Edge>::iterator it = remainE.begin();it!=remainE.end();it++){
		int temp = lca(it->start,it->des);
		int tempMax = max(maxQuery(it->start,temp),maxQuery(it->des,temp));
		ans[it->id] = tempMax-1;
		adjust(it->start,temp,it->length-1);
		adjust(it->des,temp,it->length-1);
	}
	for (int i=1;i<=m;i++){
		if (ans[i]==INF){
			printf("-1 ");
		}else{
			printf("%d ",ans[i]);
		}
	}
	return 0;
}