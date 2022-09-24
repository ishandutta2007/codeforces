#include <cstdio>
#include <vector>
#include <utility>

using namespace std;

struct End{
	int x,y,c;
};

bool B[333][333];
int E[333][333];
vector <End> V[33];

int main()
{
	int n,i,j,k,l,x,y,c;
	int ans=0;
	End p;

	scanf("%d",&n);

	p.x=150, p.y=150, p.c=1;
	V[0].push_back(p);

	for(k=1;k<=n;k++){
		scanf("%d",&l);

		for(i=0;i<V[k-1].size();i++){
			x = V[k-1][i].x, y = V[k-1][i].y, c = V[k-1][i].c;

			if(c&1) E[x-l][y] |= 130;
			if(c&2) E[x-l][y-l] |= 5;
			if(c&4) E[x][y-l] |= 10;
			if(c&8) E[x+l][y-l] |= 20;
			if(c&16) E[x+l][y] |= 40;
			if(c&32) E[x+l][y+l] |= 80;
			if(c&64) E[x][y+l] |= 160;
			if(c&128) E[x-l][y+l] |= 65;

			for(j=1;j<=l;j++){
				if(c&1) B[x-j][y] = 1;
				if(c&2) B[x-j][y-j] = 1;
				if(c&4) B[x][y-j] = 1;
				if(c&8) B[x+j][y-j] = 1;
				if(c&16) B[x+j][y] = 1;
				if(c&32) B[x+j][y+j] = 1;
				if(c&64) B[x][y+j] = 1;
				if(c&128) B[x-j][y+j] = 1;
			}
		}

		for(i=0;i<=300;i++) for(j=0;j<=300;j++) if(E[i][j]){
			p.x = i, p.y = j, p.c = E[i][j];
			V[k].push_back(p);
			E[i][j] = 0;
		}
	}

	for(i=0;i<=300;i++) for(j=0;j<=300;j++) ans += B[i][j];

	printf("%d\n",ans);

	return 0;
}