#include<bits/stdc++.h>
using namespace std;
int q,lst,tp,a,c;
long long m;
multiset<pair<int,double> >st;//dps,lpd
int main(){
	cin>>q>>m;
	for(int I=1;I<=q;I++){
		scanf("%d%d%d",&tp,&a,&c);
		a=(a+lst)%1000000+1;
		c=(c+lst)%1000000+1;
		if(tp==1){
			double b=1.0*c/a;
			auto it=st.lower_bound(make_pair(a,b));
			if(it!=st.end()&&it!=st.begin()){
				auto _it=it;_it--;
				if(1ll*(b-(*_it).second)*((*it).first-a)>=1ll*((*it).second-b)*(a-(*_it).first))
					continue;
			}
			if(it!=st.end())
				if(b>=(*it).second)
					continue;
			st.insert(make_pair(a,b));
			while(1){
				auto it=st.find(make_pair(a,b));
				if(it==st.begin())break;it--;
				if((*it).second>=b)st.erase(it);
				else break;
			}
			while(1){
				auto it=st.find(make_pair(a,b)),_it=it,__it=it;
				if(it==st.begin())break;
				_it--;
				if(_it==st.begin())break;
				__it--;__it--;
				if(1ll*((*__it).second-(*_it).second)*((*_it).first-(*it).first)>=1ll*((*_it).second-(*it).second)*((*__it).first-(*_it).first))
					st.erase(_it);
				else
					break;
			}
			while(1){
				auto it=st.find(make_pair(a,b)),_it=it,__it=it;
				_it++;
				if(it==st.end())break;
				__it++;__it++;
				if(_it==st.end())break;
				if(1ll*((*__it).second-(*_it).second)*((*_it).first-(*it).first)<=1ll*((*_it).second-(*it).second)*((*__it).first-(*_it).first))
					st.erase(_it);
				else
					break;
			}
		}else{
//			for(auto it=st.begin();it!=st.end();it++)
//				cout<<"H:"<<(*it).first<<' '<<(*it).second<<endl;
			int b=c;
			swap(a,b);
			if(st.size()==0){cout<<"NO\n";continue;}
			auto it=st.lower_bound(make_pair((a+b-1)/b,-1)),_it=it;
			if(it==st.end()){
				cout<<"NO\n";
				continue;
			}
			if(it==st.begin()){
				if(1ll*(*it).second*a<=m)
					cout<<"YES\n",lst=I;
				else
					cout<<"NO\n";
				continue; 
			}
			_it--;
			int ldps=(*_it).first,llps=(*_it).first*(*_it).second;
			int rdps=(*it).first,rlps=(*it).first*(*it).second;
			if((a-1ll*ldps*b)*rlps+(1ll*rdps*b-a)*llps<=m*(rdps-ldps))
				cout<<"YES\n",lst=I;
			else
				cout<<"NO\n";
		}
	}
}