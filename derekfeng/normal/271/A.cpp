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
int main(){
	int y;
	cin>>y;
	for (int i=y+1;;i++){
		if (i/1000!=i%1000/100 && i/1000!=i%100/10 && i/1000!=i%10 && i%1000/100!=i%100/10 && i%1000/100!=i%10 && i%100/10!=i%10){
			cout<<i;
			return 0;
		}
	}
	return 0;
}