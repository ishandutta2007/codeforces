#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <queue>
#include <sstream>
#include <stack>
#include <time.h>
#include <vector>
#include <complex>
#include <map>
#include <set>
#include <iomanip>
#include <math.h>
#include <stdlib.h>
#include <list>
#include <utility>
#include <memory>
#include <cstring>
#include <fstream>
#include <numeric>
#include <assert.h>
#include <bits/stdc++.h>
using namespace std;
const int N=200010;
int bugs,studs,exams;
pair<int,int> bug[N];
pair<int,pair<int,int> > stud[N];
set <pair<int,int> > smart;
int ans[N]; 
long long solve(int days){
	long long sum=0;
	smart.clear();
	int last=0;
	for (int i=0;i<bugs;i+=days){
		while (last<studs && stud[last].first>=bug[i].first){
			smart.insert(stud[last].second);
			last++;
		}
		if (smart.empty()){
			return (long long)1e18;
		}
		pair<int,int> t=*(smart.begin());
		smart.erase(smart.begin());
		sum+=t.first;
		for (int j=i;j<bugs && j<i+days;j++){
			ans[bug[j].second]=t.second;
		}
	}
	return sum;
}
int main(){
	scanf ("%d%d%d",&studs,&bugs,&exams);
	for (int i=0;i<bugs;i++){
		scanf ("%d",&(bug[i].first));
		bug[i].second=i;
	}
	for (int i=0;i<studs;i++){
		scanf ("%d",&(stud[i].first));
	}
	for (int i=0;i<studs;i++){
		scanf ("%d",&(stud[i].second.first)); 
		stud[i].second.second=i;
	} 
	sort (bug,bug+bugs);
	reverse (bug,bug+bugs);
	sort (stud,stud+studs);
	reverse (stud,stud+studs);
	int ll=1,rr=bugs+1;
	while(ll<rr){
		int mid=(ll+rr)>>1;
		if (solve(mid)<=exams) rr=mid;
		else ll=mid+1;
	}
	if (ll>bugs){
		printf("NO\n");
		return 0;
	}
	solve(ll);
	printf("YES\n");
	for (int i=0;i<bugs-1;i++) printf("%d ",ans[i]+1);
	printf("%d\n",ans[bugs-1]+1);
	return 0;
}