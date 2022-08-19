/****************************************************************************************************
 * author:                                                                                          *
 *                                                                                                  *
 *            #        ###                                                                          *
 *            #        ###                                                                          *
 *            #                                                                                     *
 *            #         #                                                                           *
 *    ####### #         #       ####### #               #######      # #######      # #######       *
 *   ##      ##         #      ##      ##             ##       ##    ##      ##     ##      ##      *
 *   #        #         #      #        #             #              #        #     #        #      *
 *   ##      ##         #      ##      ##             ##       ##    ##      ##     ##      ##      *
 *    ####### #         #       ####### #    #######    #######      # #######      # #######       *
 *                      #               #                            #              #               *
 *                  #   #               #                            #              #               *
 *                   ###                #                            #              #               *
 *                                      #                            #              #               *
 *                                      #                            #              #               *
 *                                                                                                  *
 ****************************************************************************************************
 * contest:                                                                                         *
 * Codeforces Round #___(Div._)                                                                     *
 ****************************************************************************************************
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include <cstdio>
#include <cctype>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <complex>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cwchar>
#include <cwctype>
#include <exception>
#include <locale>
#include <numeric>
#include <new>
#include <stdexcept>
#include <limits>
#include <valarray>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <list>
#include <utility>
#include <bitset>
#include <algorithm>
#include <functional>
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define MP make_pair
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF=1e9+7;
string str;int L;
vector<int> ans;
int main(){
	cin>>L>>str;
	str.push_back('W');L++;
	int len=0;
	rep(k,L){
		if(str[k]=='B')len++;
		else if(len>0){
			ans.push_back(len);
			len=0;
		}
	}
	printf("%d\n",ans.size());
	rep(k,ans.size())printf("%d ",ans[k]);
	return 0;
}