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
int a[3];
int main(){
	int avg=0,ans=0;
	rep(k,3)scanf("%d",&a[k]);
	sort(a,a+3);
	printf("%d",a[2]-a[0]);
	return 0;
}