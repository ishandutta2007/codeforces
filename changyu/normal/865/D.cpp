#include<bits/stdc++.h>
const int N=3e5+3;
int n,a;
long long ans;
std::priority_queue<int,std::vector<int>,std::greater<int> >q0,q1;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a);
		bool fl=0;
		if(!q0.empty()&&(q1.empty()||q0.top()<q1.top())){
			if(a>q0.top())ans+=a-q0.top(),q0.pop(),fl=1;
		}
		else if(!q1.empty()&&a>q1.top())
			ans+=a-q1.top(),q0.push(q1.top()),q1.pop(),fl=1;
		fl?q1.push(a):q0.push(a);
	}
	printf("%lld\n",ans);
	return 0;
}