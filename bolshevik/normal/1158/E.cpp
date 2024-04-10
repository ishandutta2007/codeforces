#include<iostream>
#include<vector>
int n,lim=1,fa[1024];std::vector<int> vec[1024],S[1024],d,t1,t2,v1,v2;
std::string str;std::vector<std::pair<int,int> > ans;
std::vector<int> query(std::vector<int> d){
	std::vector<int> res(n);
	std::cout<<"?";
	for(int i=0;i<n;++i) std::cout<<" "<<d[i]; 
	std::cout<<std::endl;std::cin>>str;
	for(int i=0;i<n;++i) res[i]=str[i]-48;
	return res;
}
inline void report(std::vector<std::pair<int,int> > ans){
	std::cout<<"!"<<std::endl;
	for(int i=ans.size();i--;) std::cout<<ans[i].first<<" "<<ans[i].second<<std::endl;
}
void solve(int n){
	for(d.resize(n);lim<n;lim*=2);
	vec[0].push_back(0);
	for(int i=1;i<n;++i) S[0].push_back(i);
	for(int i=lim;i>1;i/=2) for(int j=0;j<=i;j+=i){
		for(int k=0;k<n;++k) d[k]=0;
		for(int k=j;k<lim;k+=i*2) for(int $=vec[k].size();$--;) d[vec[k][$]]=i/2;
		t1=query(d);
		for(int k=j;k<lim;k+=i*2) for(int $=vec[k].size();$--;) d[vec[k][$]]=i/2-1;
		t2=query(d);
		for(int k=j;k<lim;k+=i*2){
			v1.clear();v2.clear();
			for(int $=S[k].size();$--;)
				if(t1[S[k][$]])
					if(!t2[S[k][$]]) vec[k+i/2].push_back(S[k][$]);
					else v1.push_back(S[k][$]);
				else v2.push_back(S[k][$]);
			S[k]=v1;S[k+i/2]=v2;
		}
	}
	for(int i=1;i<lim;i*=2) for(int j=0;j<3;++j){
		for(int k=0;k<n;++k) d[k]=0;
		for(int k=j;k<lim;k+=3) for(int $=vec[k].size();$--;) if(vec[k][$]&i) d[vec[k][$]]=1;
		t1=query(d);
		for(int k=j+1;k<lim;k+=3) for(int $=vec[k].size();$--;) if(t1[vec[k][$]]) fa[vec[k][$]]|=i;
	}
	for(int i=1;i<n;++i) ans.push_back(std::make_pair(fa[i]+1,i+1));
	report(ans);
}
int main(){std::cin>>n;solve(n);return 0;}