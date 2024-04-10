#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define y1 yy
#define FR first
#define SE second

using namespace std;

typedef pair<int,int> pr;

int ans1;
pr a[5],ans2[5];

int per[5],st1[5],st2[5];

inline int max(int a,int b,int c,int d) {
  return max(max(a,b),max(c,d));	
}

inline int min(int a,int b,int c,int d) {
  return min(min(a,b),min(c,d));	
}

pr calc(int a,int b,int c,int d,int len) {
  int l=0,r=5e8;
  while (l<r) {
  	int m=((l+r)>>1);
  	if (max(a-m,b-m,c-m-len,d-m-len)<=min(a+m,b+m,c+m-len,d+m-len)||
	max(a-m,b-m,c-m+len,d-m+len)<=min(a+m,b+m,c+m+len,d+m+len)) r=m; else l=m+1;
  }
  if (max(a-l,b-l,c-l-len,d-l-len)<=min(a+l,b+l,c+l-len,d+l-len)) {
  	int t=max(a-l,b-l,c-l-len,d-l-len);
  	return pr(t,t+len);
  }
  else {
  	int t=max(a-l,b-l,c-l+len,d-l+len);
  	return pr(t,t-len);
  }
}

void check() {
  pr cur[5];
  for(int i=1;i<5;i++) cur[i]=a[per[i]];
  int x1,x2,y1,y2;
  bool v1=0,v2=0,v3=0,v4=0;
  if (!st1[1]&&!st1[2]) {
  	if (cur[1].FR!=cur[2].FR) return;
  	x1=cur[1].FR;
  }
  else if (!st1[1]) x1=cur[1].FR;
  else if (!st1[2]) x1=cur[2].FR;
  else v1=1;
  if (!st1[3]&&!st1[4]) {
  	if (cur[3].FR!=cur[4].FR) return;
  	x2=cur[3].FR;
  }
  else if (!st1[3]) x2=cur[3].FR;
  else if (!st1[4]) x2=cur[4].FR;
  else v2=1;
  if (st1[1]&&st1[3]) {
  	if (cur[1].SE!=cur[3].SE) return;
  	y1=cur[1].SE;
  }
  else if (st1[1]) y1=cur[1].SE;
  else if (st1[3]) y1=cur[3].SE;
  else v3=1;
  if (st1[2]&&st1[4]) {
  	if (cur[2].SE!=cur[4].SE) return;
  	y2=cur[2].SE;
  }
  else if (st1[2]) y2=cur[2].SE;
  else if (st1[4]) y2=cur[4].SE;
  else v4=1;
  if (!v1&&!v2&&x1==x2) return;
  if (!v3&&!v4&&y1==y2) return;
  if (!v1&&!v2&&!v3&&!v4&&abs(x1-x2)!=abs(y1-y2)) return;
  if (v1&&v2) {
  	pr t=calc(cur[1].FR,cur[2].FR,cur[3].FR,cur[4].FR,abs(y1-y2));
  	x1=t.FR;x2=t.SE;
  }
  else if (v3&&v4) {
  	pr t=calc(cur[1].SE,cur[3].SE,cur[2].SE,cur[4].SE,abs(x1-x2));
  	y1=t.FR;y2=t.SE;
  }
  else if (v1) x1=x2+((st2[1])?1:-1)*abs(y1-y2);
  else if (v2) x2=x1+((st2[2])?1:-1)*abs(y1-y2);
  else if (v3) y1=y2+((st2[3])?1:-1)*abs(x1-x2);
  else if (v4) y2=y1+((st2[4])?1:-1)*abs(x1-x2);
  int len=0;
  len=max(len,(st1[1])?abs(cur[1].FR-x1):abs(cur[1].SE-y1));
  len=max(len,(st1[2])?abs(cur[2].FR-x1):abs(cur[2].SE-y2));
  len=max(len,(st1[3])?abs(cur[3].FR-x2):abs(cur[3].SE-y1));
  len=max(len,(st1[4])?abs(cur[4].FR-x2):abs(cur[4].SE-y2));
  if (len<ans1) {
  	ans1=len;
  	ans2[per[1]]=pr(x1,y1);
  	ans2[per[2]]=pr(x1,y2);
  	ans2[per[3]]=pr(x2,y1);
  	ans2[per[4]]=pr(x2,y2);
  }
}

void dfs(int d) {
  if (d>4) {
  	check();
  	return;
  }
  for(st1[d]=0;st1[d]<2;st1[d]++)
    for(st2[d]=0;st2[d]<2;st2[d]++)
      dfs(d+1);
}

int main() {
  int cases;
  scanf("%d",&cases);
  for(;cases;cases--) {
  	ans1=inf;
  	for(int i=1;i<5;i++) scanf("%d%d",&a[i].FR,&a[i].SE);
  	for(int i=1;i<5;i++) per[i]=i;
  	do {
  		dfs(1);
	  } while (next_permutation(per+1,per+5));
	if (ans1<inf) {
		printf("%d\n",ans1);
		for(int i=1;i<5;i++) printf("%d %d\n",ans2[i].FR,ans2[i].SE);
	}
	else puts("-1");
  }
  return 0;
}