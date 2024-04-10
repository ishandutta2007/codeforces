#include <cstdio>
#include <string>
#include <utility>
#include <algorithm>
#include <vector>
#include <list>
using namespace std;
typedef pair<int,string> pi;
int main(){
	int n, h, i, m;
	char name[15];
	vector<pi> pp;
	list<pi*> pl;
	scanf("%d ",&n);
	
	for(i=0;i<n;i++){
		scanf(" %s %d ",name,&h);
		pp.push_back( pi(h,string(name)) );
	}
	sort( pp.begin(), pp.end() );
	
	if( pp[0].first > 0 ){
		puts("-1");return 0;
	}
	
	pl.push_back(&pp[0]);
	for(i=1;i<n;i++){
		int k = pp[i].first;
		if(k > i){
			puts("-1");return 0;
		}
		list<pi*>::iterator it = pl.end();
		for(;k--;--it);
		pl.insert( it, &pp[i] );
	}
	h=0;
	for(list<pi*>::iterator it=pl.begin();it!=pl.end();++it){
		(*it)->first = ++h;
	}
	for(vector<pi>::iterator it=pp.begin();it!=pp.end();++it){
		printf("%s %d\n",it->second.c_str(), it->first );
	}
}