#include <cstdio>
#include <cstdlib>

int cnt[16];

int gcd(int a,int b){
  return b?gcd(b,a%b):a;
}

int boundary(int x1,int y1,int x2,int y2){
  return gcd(abs(x1-x2),abs(y1-y2));
}

//twice area
int area2(int x1,int y1,int x2,int y2,int x3,int y3){
  x2-=x1,x3-=x1;
  y2-=y1,y3-=y1;
  return x3*y2-x2*y3;
}

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    int X,Y;
    scanf("%d %d",&X,&Y);
    cnt[(X%4)*4+Y%4]++;
  }
  long long ans=0;
  for(int z1=0;z1<16;z1++){
    //printf("cnt[%d]=%d\n",z1,cnt[z1]);
    int x1=z1/4,y1=z1%4;
    for(int z2=z1;z2<16;z2++){
      int x2=z2/4,y2=z2%4;
      for(int z3=z2;z3<16;z3++){
	int x3=z3/4,y3=z3%4;
	int A2=area2(x1,y1,x2,y2,x3,y3);
	int B=boundary(x1,y1,x2,y2)
	  +boundary(x2,y2,x3,y3)
	  +boundary(x3,y3,x1,y1);
	if(A2%2==0&&A2-B%4==0){
	  if(z1==z2&&z2==z3){
	    ans+=1LL*cnt[z1]*(cnt[z1]-1)*(cnt[z1]-2)/6;
	  }else if(z1==z2){
	    ans+=1LL*cnt[z1]*(cnt[z1]-1)*cnt[z3]/2;
	  }else if(z2==z3){
	    ans+=1LL*cnt[z2]*(cnt[z2]-1)*cnt[z1]/2;
	  }else if(z3==z1){
	    ans+=1LL*cnt[z3]*(cnt[z3]-1)*cnt[z2]/2;
	  }else{
	    ans+=1LL*cnt[z1]*cnt[z2]*cnt[z3];
	  }
	}
      }
    }
  }
  printf("%lld\n",ans);
}