#include<bits/stdc++.h>

using namespace std;

struct dat{
	int l,r;
	mutable long long v;
};

bool operator<(dat a,dat b){
	return a.l<b.l;
}

const long long mdn=1000000007;

set<dat> odt;

dat nwnode(int l,int r,long long x){
	dat nw;nw.l=l;nw.r=r;nw.v=x;
	return nw; 
}

set<dat>::iterator spk(int id){
	set<dat>::iterator it=odt.lower_bound(nwnode(id,id,0));
	if(it!=odt.end()&&(*it).l==id)return it;
	it--;
	int cl=(*it).l,cr=(*it).r;
	long long cv=(*it).v;
	odt.erase(it);
	odt.insert(nwnode(cl,id-1,cv));
	return odt.insert(nwnode(id,cr,cv)).first; 
}
void ass(int l,int r,long long v){
	set<dat>::iterator itr=spk(r+1),itl=spk(l);
	odt.erase(itl,itr);
	odt.insert(nwnode(l,r,v));
}


void add(int l,int r,long long v){
	set<dat>::iterator itr=spk(r+1),it=spk(l);
	for(;it!=itr;it++){
		(*it).v+=v;
	}
}

long long ksm(long long bse,long long ex,long long md){
	if(ex==0)return 1%md;
	long long ans=ksm(bse,ex>>1,md);ans=(ans*ans)%md;
	if(ex&1)ans=(ans*bse)%md;
	return ans;
}
long long sum(int l,int r,long long x,long long md){
	set<dat>::iterator itr=spk(r+1),it=spk(l);
	long long ans=0;
	for(;it!=itr;it++){
		ans+=(long long)((*it).r-(*it).l+1)*ksm(((*it).v)%md,x,md);
		ans%=md;
	}
	return ans;
}
long long kth(int l,int r,int k){
	set<dat>::iterator itr=spk(r+1),it=spk(l);
	vector<pair<long long,int> > vec;
	for(;it!=itr;it++){
		vec.push_back(make_pair((*it).v,(*it).r-(*it).l+1)); 
	}
	sort(vec.begin(),vec.end());
	for(int i=0;i<vec.size();i++){
		if(k<=vec[i].second)return vec[i].first;
		k-=vec[i].second;
	}
}
int n,m;
long long seed,vmax;

long long rnd(){
	long long ret=seed;
	seed=(seed*7+13)%mdn;
	return ret;
}

int main(){
	ios::sync_with_stdio(0); 
	cin>>n>>m>>seed>>vmax;
	for(int i=1;i<=n;i++){
		odt.insert(nwnode(i,i,rnd()%vmax+1));
	}	
	for(int i=1;i<=m;i++){
		int op=(rnd()%4)+1;
		int l=(rnd()%n)+1;
		int r=(rnd()%n)+1;
		if(l>r)swap(l,r);
		int x,y;
		if(op==3){
			x=(rnd()%(r-l+1))+1;
		} else{
			x=(rnd()%vmax)+1;
		}
		if(op==4){
			y=(rnd()%vmax)+1;
		}
		//cerr<<op<<l<<r<<endl;
		if(op==1){
			add(l,r,x);
		}else if(op==2){
			ass(l,r,x);
		}else if(op==3){
			cout<<kth(l,r,x)<<'\n';
		}else{
			cout<<sum(l,r,x,y)<<'\n';
		}
	}
	return 0;
}