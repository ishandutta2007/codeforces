#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N=100000;

int n,m,a[N+9];
char s[5];

void into(){
  scanf("%d",&n);
  for (int i=1;i<=n;++i)
	scanf("%d",&a[i]);
  scanf("%s",s);
  m=strlen(s);
  sort(s,s+m);
}

char ans[N+9];
struct seg{
  int l,r,v;
  seg(int L=0,int R=0,int V=0){l=L;r=R;v=V;}
};

void Get_ans(int l,int r){
  for (;l<=r&&a[l]==1;++l) ans[l+1]='+';
  for (;r>=l&&a[r]==1;--r) ans[r]='+';
  if (l>=r) return;
  int lim=(r-l+1)*2+6,ml=1;
  for (int i=l;i<=r;++i) ml=min(ml*a[i],lim);
  if (ml>=lim){
	for (int i=l+1;i<=r;++i) ans[i]='*';
	return;
  }
  vector<seg>pos;
  vector<int>num;
  for (int i=l;i<=r;)
	if (a[i]==1){
	  int x=i;
	  for (;i<=r&&a[i]==1;++i);
	  pos.emplace_back(x,i-1,i-x);
	}else{
	  int x=1,j=i+1;
	  for (;i<=r&&a[i]>1;++i) x*=a[i];
	  for (;j<i;++j) ans[j]='*';
	  num.push_back(x);
	}
  int mx=0,val=ml;
  for (int vs=pos.size(),s=1;s<1<<vs;++s){
	int now=0;
	for (int i=0,ml=num[0];i<vs;++i){
	  if (s>>i&1){
		now+=ml+pos[i].v;
		ml=num[i+1];
	  }else ml*=num[i+1];
	  if (i+1==vs) now+=ml;
	}
	if (now>val) mx=s,val=now;
  }
  for (int vs=pos.size(),i=0;i<vs;++i)
	for (int j=pos[i].l;j<=pos[i].r+1;++j) ans[j]=mx>>i&1?'+':'*';
}

void work(){
  if (m==1){
	printf("%d",a[1]);
	for (int i=2;i<=n;++i)
	  printf("%c%d",s[0],a[i]);
    puts("");
    return;
  }
  if (m==2&&s[0]=='+'&&s[1]=='-'){
	printf("%d",a[1]);
	for (int i=2;i<=n;++i)
	  printf("+%d",a[i]);
    puts("");
	return;
  }
  if (m==2&&s[0]=='*'&&s[1]=='-'){
	int flag=0;
	for (int i=1;i<=n;++i){
	  if (!flag&&!a[i]){
		flag=1;
		if (i>1) putchar('-');
		printf("%d",a[i]);
		continue;
	  }
	  if (i>1) putchar('*');
	  printf("%d",a[i]);
	}
	puts("");
	return;
  }
  for (int l=1,r=1;r<=n+1;++r)
	if (!a[r]){
	  ans[r]=ans[r+1]='+';
	  if (l<r) Get_ans(l,r-1);
	  l=r+1;
	}
  printf("%d",a[1]);
  for (int i=2;i<=n;++i)
	printf("%c%d",ans[i],a[i]);
  puts("");
}

void outo(){
}

int main(){
  int T=1;
  //scanf("%d",&T);
  for (;T--;){
    into();
    work();
    outo();
  }
  return 0;
}