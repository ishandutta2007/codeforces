#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e5+100;
tuple <int,int,int> x[MAX],y[MAX];
tuple<int,int> ans[MAX];
int id[MAX];
int n,w,h,xtot,ytot;
void input(){
	scanf("%d%d%d",&n,&w,&h);
	for (int i=1;i<=n;i++){
		int g,p,t;
		scanf("%d%d%d",&g,&p,&t);
		if (g==1){
			ans[i] = make_tuple(p,h);
			x[xtot++] = make_tuple(t-p,p,i); 
		}else{
			ans[i] = make_tuple(w,p);
			y[ytot++] = make_tuple(t-p,p,i);
		}
		id[i]=i;
	}
}
bool cmp(tuple<int,int,int> a,tuple<int,int,int> b){
	if (get<0>(a)==get<0>(b)){
		return get<1>(a)<get<1>(b);
	}
	return get<0>(a)<get<0>(b);
}
void solve(){
	sort(x,x+xtot,cmp);
	sort(y,y+ytot,cmp);
	/*
	for (int i=0;i<xtot;i++){
		printf("x[%d]=(%d,%d,%d)\n",i,get<0>(x[i]),get<1>(x[i]),get<2>(x[i]));
	}
	for (int i=0;i<ytot;i++){
		printf("y[%d]=(%d,%d,%d)\n",i,get<0>(y[i]),get<1>(y[i]),get<2>(y[i]));
	}
	*/
	for (int i=0,j=0,ii,jj;i<xtot;i=ii){
		int xx = get<0>(x[i]);
		ii=i;
		while(ii<xtot&&get<0>(x[ii])==xx){
			ii++;
		} 
		while (j<ytot&&get<0>(y[j])<xx){
			j++;
		}
		jj =j;
		while (jj<ytot&&get<0>(y[jj])==xx){
			jj++;
		}
		int sx = ii-i;
		int sy = jj-j;
		if (sy==0){
			continue;
		}
//		cout<<xx<<" "<<i<<","<<ii<<" "<<j<<","<<jj<<endl;
		for (int k=i;k<ii;k++){
			if (sy>=ii-k){
				id[get<2>(x[k])] = get<2>(y[j+ii-1-k]);
			}else{
				id[get<2>(x[k])] = get<2>(x[k+sy]);
			}
		}
		for (int k=j;k<jj;k++){
			if (sx>=jj-k){
				id[get<2>(y[k])] = get<2>(x[i+jj-k-1]);
			}else{
				id[get<2>(y[k])] = get<2>(y[k+sx]);
			}
		}
	}
	for (int i=1;i<=n;i++){
		printf("%d %d\n",get<0>(ans[id[i]]),get<1>(ans[id[i]]));
	}
}
int main(){
	input();
	solve();
	return 0;
}