#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
struct pa{
	int dest,val,ind;
	pa(int a=0, int b=0, int c=0):dest(a),val(b),ind(c){}
};
vector<pa> matrix[1001];
int deg[1001];
bool edgesdone[1001];
int dfsedge(int loc, int parent){
	for(pa a:matrix[loc]){
		if(a.dest!=parent)return dfsedge(a.dest,loc);
	}
	return loc;
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	int a,b,c;
	for(int i=0;i<n-1;i++){
		cin>>a>>b>>c;
		deg[a] += 1;
		deg[b] += 1;
		matrix[a].push_back(pa(b,c,i));
		matrix[b].push_back(pa(a,c,i));
	}
	queue<pa> touse;
	for(int i=1;i<=n;i++){
		if(deg[i]==2){
			printf("NO\n");
			return 0;
		}
	}
	vector<pa> moves;//ind is integermove
	for(int i=1;i<=n;i++){
		if(deg[i]>=3){
			for(pa x:matrix[i]){
				if(!edgesdone[x.ind]){
					edgesdone[x.ind]=true;
					vector<int> leafs;
					for(int j=0;j<3&&leafs.size()<2;j++){
						if(matrix[i][j].ind!=x.ind){
							leafs.push_back(dfsedge(matrix[i][j].dest,i));
						}
					}
					vector<int> othleft;
					if(deg[x.dest]!=1){
						for(int j=0;j<3&&othleft.size()<2;j++){
							if(matrix[x.dest][j].dest!=i){
								othleft.push_back(dfsedge(matrix[x.dest][j].dest,x.dest));
							}
						}
					}
					else{
						othleft={dfsedge(x.dest,i)};
						othleft.push_back(othleft[0]);
					}
					moves.push_back(pa(othleft[0],leafs[0],x.val/2));
					moves.push_back(pa(othleft[1],leafs[1],x.val/2));
					moves.push_back(pa(leafs[1],leafs[0],-(x.val/2)));
					if(othleft[0]!=othleft[1])moves.push_back(pa(othleft[1],othleft[0],-(x.val/2)));
				}
			}
		}
	}
	if(n==2){
		printf("YES\n%d\n%d %d %d\n",1,1,2,matrix[1][0].val);
	}
	else{
		printf("YES\n%d\n",moves.size());
		for(pa x:moves){
			printf("%d %d %d\n",x.dest,x.val,x.ind);
		}
	}
	return 0;
}