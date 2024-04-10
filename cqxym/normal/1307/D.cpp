#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
#define R register int
struct Node{
    int Num,dis;
    inline bool operator<(const Node &a)const{
        return a.dis<dis;
    }
};
struct Path{
	int dis1,disn;
	inline friend bool operator<(Path x,Path y){
		if(x.dis1==y.dis1){
			return x.disn<y.disn;
		}
		return x.dis1<y.dis1;
	}
}p[200001];
vector<int>G[200001];
int dis[200001],n,key[200001],mx[200001];
bool v[200001];
inline void Dijkstra(int s){
    int u,w,l;
    for(R i=1;i<=n;i++){
    	v[i]=false;
        dis[i]=1e9;
    }
    dis[s]=0;
    priority_queue<Node>Q;
    Node temp;
    temp.Num=s;
    temp.dis=0;
    Q.push(temp);
    while(Q.empty()==false){
        u=Q.top().Num;
        Q.pop();
        if(v[u]==true){
            continue;
        }
        v[u]=true;
        l=G[u].size();
        for(R i=0;i<l;i++){
            w=G[u][i];
            if(v[w]==false&&dis[w]>dis[u]+1){
                dis[w]=dis[u]+1;
                temp.Num=w;
                temp.dis=dis[w];
                Q.push(temp);
            }
        }
    }
}
inline int Max(int x,int y){
	return x<y?y:x;
}
inline int Min(int x,int y){
	return x>y?y:x;
}
int main(){
    int m,k,x,y;
    scanf("%d%d%d",&n,&m,&k);
    for(R i=1;i<=k;i++){
    	scanf("%d",key+i);
	}
    for(R i=0;i!=m;i++){
    	scanf("%d%d",&x,&y);
    	G[x].push_back(y);
    	G[y].push_back(x);
	}
	Dijkstra(1);
	int curans=dis[n];
	for(R i=1;i<=k;i++){
		p[i].dis1=dis[key[i]];
	}
	Dijkstra(n);
	for(R i=1;i<=k;i++){
		p[i].disn=dis[key[i]];
	}
	sort(p+1,p+k+1);
	mx[k]=p[k].disn;
	for(R i=k-1;i!=0;i--){
		mx[i]=Max(p[i].disn,mx[i+1]);
	}
	int ans=0;
	for(R i=1;i!=k;i++){
		Path T;
		int lf=Min(p[i].dis1,p[i].disn),rt=2e5,mid,cur;
		T.disn=0;
		while(lf<=rt){
			mid=lf+rt>>1;
			T.dis1=mid-p[i].disn;
			int upd=lower_bound(p+i+1,p+k+1,T)-p;
			if(mx[upd]+p[i].dis1>=mid){
				cur=mid;
				lf=mid+1;
			}else{
				rt=mid-1;
			}
		}
		ans=Max(ans,cur+1);
	}
	printf("%d",Min(ans,curans));
    return 0;
}