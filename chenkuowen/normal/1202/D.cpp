#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<pair<int,int> > pos;
ll sum[100005];
int main(){
	int T; scanf("%d",&T);
	for(int i=1;i<=100000;++i) sum[i]=sum[i-1]+i;
	while(T--){ 
		int n,cnt=1; scanf("%d",&n);
		pos.clear();
		for(int i=100000;i>=1;--i)
			if(n>=sum[i]){
				pos.push_back(make_pair(i,0));
				while(n>=sum[i]){
					n-=sum[i];
					pos[pos.size()-1].second++;
				}
			}
		pos.push_back(make_pair(0,0));
		for(int i=0;i<pos.size()-1;++i){
	//		printf("<%d %d>",pos[i].first,pos[i].second);
			for(int j=0;j<pos[i].second;++j)
				putchar('1');
			for(int j=0;j<pos[i].first-pos[i+1].first;++j)
				putchar('3');
		}
		putchar('3');
		putchar('7');
		puts("");
//		printf("(%d)",n+cnt+1);
	}
}