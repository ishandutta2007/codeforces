#include<bits/stdc++.h>
//using namespace std;
int n,m,ans=0;
int map[30][30];
bool check(int x1,int y1,int x2,int y2){
	for(int i=x1;i<=x2;i++)
        for(int j=y1;j<=y2;j++)
            if(map[i][j]==1)
                return false;
    return true;
} 
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%1d",&map[i][j]);
	for(int x1=1;x1<=n;x1++)
		for(int x2=x1;x2<=n;x2++)
			for(int y1=1;y1<=m;y1++)
				for(int y2=y1;y2<=m;y2++)
					if(check(x1,y1,x2,y2))
						ans=std::max(ans,(x2-x1+y2-y1+2)*2);
	printf("%d",ans);
}