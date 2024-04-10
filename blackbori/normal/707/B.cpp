#include <cstdio>
#include <vector>

using namespace std;

int n,m,k,a,b,c,ans=1e9+1e8,i,j;

struct kk{
	int x,c;
};

vector <kk> D[101010];
vector <int> vv;
bool check[101010];

int main()
{
	scanf("%d %d %d",&n,&m,&k);

	for(i=0;i<m;i++){
		scanf("%d %d %d",&a,&b,&c);
		kk _k;
		_k.x=b, _k.c=c;
		D[a].push_back(_k);
		_k.x=a, _k.c=c;
		D[b].push_back(_k);
	}

//	for(i=1;i<=n;i++) printf("%d %d\n",i,D[i]);

	for(i=0;i<k;i++){
		scanf("%d",&a);
		vv.push_back(a);
		check[a] = 1;
	}
	for(i=0;i<k;i++){
		a=vv[i];
		int m=1e9+1e8;

		for(j=0;j<D[a].size();j++){
			if(check[D[a][j].x]==0 && D[a][j].c<m) m=D[a][j].c;
		}

		if(ans > m) ans=m;
	}

	printf("%d\n",ans==1e9+1e8?-1:ans);

	return 0;
}