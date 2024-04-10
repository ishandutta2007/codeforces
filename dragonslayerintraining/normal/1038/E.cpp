#include <cstdio>
#include <set>
#include <algorithm>

int index[4][4]={{0,4,5,6},
		 {4,1,7,8},
		 {5,7,2,9},
		 {6,8,9,3}};
int ends[10][2];

int sum[10];
int min[10];
int cnt[10];

int find(int uf[4],int a){
  while(a!=uf[a]) a=uf[a];
  return a;
}

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<10;i++){
    min[i]=1e9;
  }
  for(int i=0;i<4;i++){
    for(int j=i;j<4;j++){
      int ind=index[i][j];
      ends[ind][0]=i,ends[ind][1]=j;
    }
  }
  for(int i=0;i<N;i++){
    int C1,V,C2;
    scanf("%d %d %d",&C1,&V,&C2);
    C1--,C2--;
    int ind=index[C1][C2];
    sum[ind]+=V;
    min[ind]=std::min(min[ind],V);
    cnt[ind]++;
  }
  int best=0;
  for(int vs=0;vs<(1<<4);vs++){
    int es=0;
    for(int i=0;i<4;i++){
      if(vs&(1<<i)){
	for(int j=i;j<4;j++){
	  if(vs&(1<<j)){
	    if(cnt[index[i][j]]){
	      es|=(1<<index[i][j]);
	    }
	  }
	}
      }
    }
    for(int os=0;os<(1<<10);os++){
      if((os&es)!=os) continue;
      int parity[4]={};
      for(int e=0;e<10;e++){
	if(es&(1<<e)){
	  int p=((cnt[e]^(os>>e))&1);
	  parity[ends[e][0]]^=p;
	  parity[ends[e][1]]^=p;
	}
      }
      int odd=0;
      for(int i=0;i<4;i++){
	if(parity[i]) odd++;
      }
      if(odd>2) continue;
      {
	int uf[4]={0,1,2,3};
	bool bad=false;
	for(int e=0;e<10;e++){
	  if(es&(1<<e)){
	    int times=cnt[e];
	    if(os&(1<<e)) times--;
	    if(times<0){
	      bad=true;
	      break;
	    }
	    if(times>0){
	      uf[find(uf,ends[e][0])]=find(uf,ends[e][1]);
	    }
	  }
	}
	if(bad) continue;
	std::set<int> cmpt;
	for(int v=0;v<4;v++){
	  if(vs&(1<<v)){
	    cmpt.insert(find(uf,v));
	  }
	}
	if(cmpt.size()>1) continue;
      }
      int score=0;
      for(int e=0;e<10;e++){
	if(es&(1<<e)){
	  score+=sum[e];
	  if(os&(1<<e)){
	    score-=min[e];
	  }
	}
      }
      //printf("V:%d E:%d O:%d score=%d\n",vs,es,os,score);
      best=std::max(best,score);
    }
  }
  printf("%d\n",best);
  return 0;
}