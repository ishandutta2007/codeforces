/*
	



  







 

*/
/*



 . 











	 
 
...

.

 









	










 
 


   
/
    
   
  



----------
---
--
------
---
---------------- 






 
 

------
--
--------
--



   

  
 
 / 
 
~*~*~
*~*~






?









??
???
???
__ __?
?

?




..o+?''o?''oo+?''o?''o
------
---
---
-
--
o+?''o?''oo+?''o?''o






	


 



      
<  >    
      

 

-------




-
-------
 
 ----

..


..
..

""























*/

/*
			  ********
               ************
               ####....#.
             #..###.....##....
             ###.......######              ###                 ###           ###           ###
                ...........               #...#               #...#         #...#         #...#
               ##*#######                 #.#.#               #.#.#         #.#.#         #.#.#
            ####*******######             #.#.#               #.#.#         #.#.#         #.#.#
           ...#***.****.*###....          #...#               #...#         #...#         #...#
           ....**********##.....           ###                 ###           ###           ###
           ....****    *****....
             ####        ####
           ######        ######
##############################################################              ##################################
#...#......#.##...#......#.##...#......#.##------------------#              #...#......#.##------------------#
###########################################------------------#              ###############------------------#
#..#....#....##..#....#....##..#....#....#####################              #..#....#....#####################
##########################################    #----------#                  ##############    #----------#
#.....#......##.....#......##.....#......#    #----------#                  #.....#......#    #----------#
##########################################    #----------#                  ##############    #----------#
#.#..#....#..##.#..#....#..##.#..#....#..#    #----------#                  #.#..#....#..#    #----------#
##########################################    ############                  ##############    ############
*/
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <climits>
#include <string.h>
#include <stdio.h>
#define LL long long
#define pii pair<int,int>
#define piii pair<int, pii >
#define REP(i,n) for (int (i)=0;(i)<(n);(i)++)
#define vi vector<int>
#define vpi vector< pii >
#define INF 2147483647
#define pb push_back
#define mp make_pair
using namespace std;
const int Maxn=100005;
int a[Maxn];
int col[Maxn];
long long sum[Maxn];
vector<pair<int,int> > q;
multiset<long long> s;
int main(){
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]+a[i];
	}
	int cnt=0;
	s.insert(sum[n]);
	q.push_back(make_pair(1,n));
	for (int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		int c=col[x];
		int start=q[c].first,end=q[c].second;
		if (start==end){
			s.erase(s.find(a[x]));
			//continue;
		}
		else{
			if (start==x){
				q[c].first++;
				s.erase(s.find(sum[end]-sum[start-1]));
				s.insert(sum[end]-sum[start]);
			}
			else if (x==end){
				q[c].second--;
				s.erase(s.find(sum[end]-sum[start-1]));
				s.insert(sum[end-1]-sum[start-1]);
			}
			else{
				int l=x-start,r=end-x;
				if (l<r){
					q[c].first=x+1;
					s.erase(s.find(sum[end]-sum[start-1]));
					s.insert(sum[end]-sum[x]);
					s.insert(sum[x-1]-sum[start-1]);
					cnt++;
					for (int j=start;j<=x-1;j++){
						col[j]=cnt;
					}
					q.push_back(make_pair(start,x-1));
				}
				else{
					q[c].second=x-1;
					s.erase(s.find(sum[end]-sum[start-1]));
					s.insert(sum[end]-sum[x]);
					s.insert(sum[x-1]-sum[start-1]);
					cnt++;
					for (int j=x+1;j<=end;j++){
						col[j]=cnt;
					}
					q.push_back(make_pair(x+1,end));
				}
			}
		}
		if (s.empty()) printf("0\n");
		else{
			set<long long> ::iterator it=s.end();
			it--;
			printf("%I64d\n",*it);
		}
		
	}
	return 0;
}