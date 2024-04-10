#include<bits/stdc++.h>

using namespace std;

const int maxn=100005;

int n,m,k;
set<int> o1[maxn],o2[maxn];
 
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m>>k;
	long long sm=((long long)n)*m-k;
	while(k--){
		int x,y;
		cin>>x>>y;
		o1[x].insert(y);
		o2[y].insert(x); 
	}	
	for(int i=1;i<=n;i++){
		o1[i].insert(0);o1[i].insert(m+1);
	}
	for(int i=1;i<=m;i++){
		o2[i].insert(0);o2[i].insert(n+1);
	}
	int cx=1,cy=0,lb=0,rb=m+1,ub=1,db=n+1,typ=0;
	while(1){
		if(typ%4==0){
			rb=min(rb,*o1[cx].upper_bound(cy));
			if(rb==cy+1)break;
			rb--;
			sm-=rb-cy;
			cy=rb;
		}else if(typ%4==1){
			db=min(db,*o2[cy].upper_bound(cx));
			if(db==cx+1)break;
			db--;
			sm-=db-cx;
			cx=db;
		}else if(typ%4==2){
			lb=max(lb,*(--o1[cx].lower_bound(cy)));
			if(lb==cy-1)break;
			lb++;
			sm-=cy-lb;
			cy=lb;
		}else if(typ%4==3){
			ub=max(ub,*(--o2[cy].lower_bound(cx)));
			if(ub==cx-1)break;
			ub++;
			sm-=cx-ub;
			cx=ub;
		}
		typ++;
	}
	cerr<<sm<<endl;
	cout<<(sm?"No":"Yes");
	return 0;
}