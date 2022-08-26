#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <float.h>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <locale>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <wchar.h>
#include <wctype.h>
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cerrno>
#include <clocale>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <limits>
#include <map>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <istream>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <utility>
#include <vector>
#include <cwchar>
#include <cwctype>
#include <complex.h>
#include <fenv.h>
#define mp make_pair
#define fs first
#define se second
using namespace std;
int e[305][305];
int a[305];
int main(){
	ios_base::sync_with_stdio(false);
	int n,i,j,k,cur;
	cin>>n;
	char c;
	for(i=0;i<n;i++) cin>>a[i];
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			cin>>c;
			e[i][j]=c-'0';
		}
	}     
	for(k=0;k<n;k++) for(i=0;i<n;i++) for(j=0;j<n;j++) if(e[i][k]&&e[k][j]) e[i][j]=true;
	for(i=0;i<n;i++){
		cur=i;
		for(j=i+1;j<n;j++) if(a[cur]>a[j]&&e[i][j]) cur=j;
		swap(a[cur],a[i]);
	}
	for(i=0;i<n;i++) cout<<a[i]<<" ";
	cout<<'\n';
	return 0;
}