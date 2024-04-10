#include<cstdio>
#include<queue>
#include<map>
const int N=2003;
int n,a[N],ans=N;std::priority_queue<int>p,del;std::map<int,int>b,used;
inline void Out(std::priority_queue<int>&p){
	std::priority_queue<int> tmp;
	tmp=p;
	for(;!tmp.empty();tmp.pop())printf("%d ",tmp.top());
	puts("");
}
int main(){
	bool f;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
	  scanf("%d",a+i);
	  b[a[i]]++;
	}
	for(int i=1;i<=n;i++)
	  if(!used[a[i]])p.push(b[a[i]]),used[a[i]]=1;
	if(p.top()<=1)return 0*puts("0");
	for(int i=1,j=1;i<=n;i++){
	  del.push(b[a[i]]);b[a[i]]--;p.push(b[a[i]]);
	  for(;!del.empty()&&p.top()==del.top();p.pop(),del.pop());
	  f=p.top()<=1;
	  for(;j<=i;j++){
		if(p.top()>1)break;
		del.push(b[a[j]]);b[a[j]]++;p.push(b[a[j]]);
		for(;!del.empty()&&p.top()==del.top();p.pop(),del.pop());
	  }
	  if(f)ans=std::min(ans,i-j+2);
	}printf("%d",ans);
	return 0;
}