#include <cstdio>
#include <algorithm>
#include <numeric>

int N;
int ps[200005];
int leftext[200005];
int rightext[200005];
int leftabove[200005];
int leftbelow[200005];
int rightabove[200005];
int rightbelow[200005];
int far[200005];

int main(){
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&ps[i]);
  }
  {
    int above=-1,below=-1;
    int leftmost=0;
    for(int i=0;i<N;i++){
      if(i>0){
	if(ps[i]>ps[i-1]){
	  below=i-1;
	  if(above!=-1&&ps[i]>ps[above]){
	    leftmost=std::max(leftmost,above+1);
	    above=-1;
	  }
	}else{
	  above=i-1;
	  if(below!=-1&&ps[i]<ps[below]){
	    leftmost=std::max(leftmost,below+1);
	    below=-1;
	  }
	}
      }
      leftext[i]=leftmost;
      leftabove[i]=above;
      leftbelow[i]=below;
    }
  }
  {
    int above=-1,below=-1;
    int rightmost=N-1;
    for(int i=N-1;i>=0;i--){
      if(i<N-1){
	if(ps[i]>ps[i+1]){
	  below=i+1;
	  if(above!=-1&&ps[i]>ps[above]){
	    rightmost=std::min(rightmost,above-1);
	    above=-1;
	  }
	}else{
	  above=i+1;
	  if(below!=-1&&ps[i]<ps[below]){
	    rightmost=std::min(rightmost,below-1);
	    below=-1;
	  }
	}
      }
      rightext[i]=rightmost;
      rightabove[i]=above;
      rightbelow[i]=below;
    }
  }

  std::iota(far,far+N,0);
  for(int i=0;i<N;i++){
    int l=leftext[i],r=rightext[i];
    //printf("[%d,%d] is good\n",l,r);
    far[r]=std::min(far[r],l);
  }
  for(int i=0;i<N-1;i++){
    if(ps[i]>ps[i+1]){
      if(leftbelow[i]!=-1&&rightabove[i+1]!=-1&&ps[leftbelow[i]]<ps[rightabove[i+1]]){
	far[rightext[i+1]]=std::min(far[rightext[i+1]],leftext[i]);
      }
    }else{
      if(leftabove[i]!=-1&&rightbelow[i+1]!=-1&&ps[leftabove[i]]>ps[rightbelow[i+1]]){
	far[rightext[i+1]]=std::min(far[rightext[i+1]],leftext[i]);
      }
    }
  }
  for(int i=N-2;i>=0;i--){
    far[i]=std::min(far[i],far[i+1]);
  }
  long long ans=0;
  for(int i=0;i<N;i++){
    //printf("far[%d]=%d\n",i,far[i]);
    ans+=i-far[i]+1;
  }
  printf("%lld\n",ans);
}