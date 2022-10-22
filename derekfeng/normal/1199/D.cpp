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
#include <bitset>
#include <ios> 
#include <bits/stdc++.h>
using namespace std;
int n;
int giveyou[200004],dat[200004],w[200004]; 
int main(){
	cin>>n;
	for (int i=1;i<=n;i++){
		scanf ("%d",&dat[i]);
		w[i]=-1;
	}
	int q;cin>>q;
	for (int i=1;i<=q;i++){
		int x,y;
		int oper;scanf("%d",&oper);
		if (oper==1){
			scanf ("%d%d",&x,&y);
			dat[x]=y;w[x]=i;
		}else{
			scanf ("%d",&y);
			giveyou[i]=y;
		}
	}
	for (int i=q;i>=0;i--) giveyou[i]=max(giveyou[i+1],giveyou[i]);
	for (int i=1;i<=n;i++){
		int o=giveyou[w[i]+1];
		if (o<dat[i]) printf("%d ",dat[i]);
		else printf("%d ",giveyou[w[i]+1]);
	}
}