#include <bits/stdc++.h>
using namespace std;
#define pb push_back;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
const int MAXN=2e5+1;
vector<pii> matrix[MAXN];
bool cent[MAXN];
int subtreesize[MAXN];
int dfssize(int loc, int parent){
	subtreesize[loc]=1;
	for(pii x:matrix[loc])if(x.first!=parent&&!cent[x.first])subtreesize[loc]+=dfssize(x.first,loc);
	return subtreesize[loc];
}
int decompsubtree(int loc, int parent, int size){
	for(pii x:matrix[loc]){
		if(x.first!=parent&&!cent[x.first]&&subtreesize[x.first]>size)return decompsubtree(x.first,loc,size);
	}
	return loc;
}
vector<int> toadd;
lli sum[MAXN];
lli bit[MAXN];
void update(int loc, lli am){
	for(;loc<MAXN;loc+=loc&-loc){
		bit[loc]+=am;
	}
}
lli query(int loc){
	lli sum=0;
	for(;loc>0;loc-=loc&-loc){
		sum+=bit[loc];
	}
	return sum;
}
void dfs(int loc, int parent, int ma,bool check){
	if(check){
		sum[ma]+=1;
		sum[ma]+=query(ma);
	}
	else sum[ma]+=query(ma-1);
	toadd.push_back(ma);
	for(pii x:matrix[loc]){
		if(!cent[x.first]&&x.first!=parent)dfs(x.first,loc,max(x.second,ma),check);
	}
}
void decompfulltree(int loc){
	int next=decompsubtree(loc,-1,dfssize(loc,-1)/2);
	cent[next]=true;
	vector<int> tominus;
	for(pii x:matrix[next]){
		if(!cent[x.first]){
			dfs(x.first,next,x.second,true);
			for(int x:toadd){
				update(x,1);
				tominus.push_back(x);
			}
			toadd.clear();
		}
	}
	for(int x:tominus){
		update(x,-1);
	}
	tominus.clear();
	for(int i=matrix[next].size()-1;i>=0;i--){
		if(!cent[matrix[next][i].first]){
			dfs(matrix[next][i].first,next,matrix[next][i].second,false);
			for(int x:toadd){
				update(x,1);
				tominus.push_back(x);
			}
			toadd.clear();
		}
	}
	for(int x:tominus){
		update(x,-1);
	}
	tominus.clear();
	for(pii x:matrix[next]){
		if(!cent[x.first])decompfulltree(x.first);
	}
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    int a,b,c;
	for(int i=1;i<n;i++){
		cin>>a>>b>>c;
		matrix[a].push_back({b,c});
		matrix[b].push_back({a,c});
	}
	decompfulltree(1);
	for(int i=1;i<MAXN;i++){
		sum[i]+=sum[i-1];
	}
	for(int i=0;i<m;i++){
		cin>>a;
		printf("%lli ",sum[a]);
	}
    return 0;
}