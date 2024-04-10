#include <cstdio>
#include <cstring>

int ps[100];

double weight[100][100];
double tmp[100][100];

int main(){
  int N,K;
  scanf("%d %d",&N,&K);
  for(int i=0;i<N;i++){
    scanf("%d",&ps[i]);
  }
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(ps[i]<ps[j]){
	weight[i][j]=1;
      }else{
	weight[j][i]=1;
      }
    }
  }
  while(K--){
    for(int x=0;x<N;x++){
      for(int y=0;y<N;y++){
	if(x==y) continue;
	for(int l=0;l<N;l++){
	  for(int r=l;r<N;r++){
	    int fx=(x>=l&&x<=r)?(l+r-x):x;
	    int fy=(y>=l&&y<=r)?(l+r-y):y;
	    tmp[fx][fy]+=weight[x][y]*(2.0/N/(N+1));
	  }
	}
      }
    }
    memcpy(weight,tmp,sizeof(tmp));
    memset(tmp,0,sizeof(tmp));
  }
  double ans=0;
  for(int i=0;i<N;i++){
    for(int j=0;j<i;j++){
      ans+=weight[i][j];
    }
  }
  printf("%.10lf\n",ans);
}