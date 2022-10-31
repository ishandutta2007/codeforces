#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define N 11111
bool sign(pair <LL,LL> x){
	if (x.first>=0) return true;
	return false; 
}
pair <LL,LL> a[N];
vector < pair<LL,LL> > vec;
LL C(LL x,LL y){
	if (y==3) return x*(x-1)*(x-2)/6;
	else if (y==4) return x*(x-1)*(x-2)*(x-3)/24;
}
bool isleft(pair <LL,LL> x,pair <LL,LL> y){
	return x.first*y.second>x.second*y.first;
}
bool cmp(pair <LL,LL> x,pair <LL,LL> y){
	if (sign(x)!=sign(y)) return sign(x);
	return isleft(x,y);
}
int main(){
	LL n;scanf("%lld",&n);
	for (int i=0;i<n;++i){
		LL x,y;
		scanf("%lld%lld",&x,&y);
		a[i]=make_pair(x,y);
	}
	LL ans=0;
	for (int i=0;i<n;++i){
		vec.clear();
		for (int j=0;j<n;++j){
            if (i!=j){
                vec.push_back(make_pair(a[j].first-a[i].first,a[j].second-a[i].second));
            }
        }
		sort(vec.begin(),vec.end(),cmp);
		ans+=C(n-1,4);
		LL cnt=0,p=0;
		for (int i=0;i<n-1;++i){
			if (p==i){
				p=i+1;cnt=0;
			}
			if (p==n-1) p=0;
			while (p!=i && isleft(vec[i],vec[p])){
				p++;cnt++;
				if (p==n-1) p=0;
			}
			ans-=C(cnt,3);
			cnt--;
		}
	}
	cout<<ans<<endl;
}