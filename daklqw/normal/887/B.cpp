#include <iostream>
#include <cstdio>
using namespace std;
bool can[1010];
int n,cube[4][10];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    	for(int j=1;j<=6;++j){
			scanf("%d",&cube[i][j]);
			can[cube[i][j]]=true;
		}
	if(n>1){
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				if(i!=j)
					for(int p=1;p<=6;++p)
						for(int q=1;q<=6;++q)
							can[cube[i][p]*10+cube[j][q]]=true;
	}
	if(n>2){
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				for(int k=1;k<=n;++k)
					if(i!=j&&j!=k&&k!=i)
						for(int t1=1;t1<=6;++t1)
							for(int t2=1;t2<=6;++t2)
								for(int t3=1;t3<=6;++t3)
		can[cube[i][t1]*100+cube[j][t2]*10+cube[k][t3]]=true;
	}
	for(int i=1;i<=1000;++i)
		if(!can[i]){
			printf("%d\n",i-1);
			return 0;
		}
    return 0;
}